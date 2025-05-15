#include "GameManager.h"
//#include <windows.h>
//#include "UIHelper.h" // �����ڷ�װ��ť����

GameManager::GameManager() : page(1), mode(0) {}
GameManager::~GameManager() {
    delete startupScene;
    delete homeScene;
    delete mode1Scene;
    delete mode2Scene;
    delete mode3Scene;
    delete gameScene;
    delete game2Scene;
    delete game3Scene;
    delete resultScene;
    delete introScene;
    delete me;
    closegraph();
}

void GameManager::init() {
    initgraph(1366, 780);
    res.loadAll(); // ������Դ
    //res.playIntroVideo();
    res.BGM();
    me = new PlayerMe();
    startupScene = new StartScene(&res, [this]() { this->switchToHome(); });//����ص�����
    homeScene = new HomeScene(&res, [this](int mode) {
    if (mode == 1) switchToMode1();
    else if (mode == 2) switchToMode2();
    else if (mode == 3) switchToMode3(); });//�൱��HomeScene�Դ�һ���ص��Ĳ�����Ȼ�����˶�Ӧ����֮��
                                            //����ص������Ͱѱ���Ĳ�������������ʵ����ģʽ�ı仯
    mode1Scene = new Mode1Scene(&res, [this](PlayerType who) {//����PlayerType
        this->switchToGameScene(who);
        });
    mode2Scene = new Mode2Scene(&res, [this](PlayerType who){
        this->switchToGame2Scene(who); 
        });//����PlayerType
 
    mode3Scene = new Mode3Scene(&res, [this]() {
        this->switchToGame3Scene();
        });

    mode1Scene->setHomeCallback([this]() { this->switchToHome(); });
    mode2Scene->setHomeCallback([this]() { this->switchToHome(); });    
    mode3Scene->setHomeCallback([this]() { this->switchToHome(); });
    
    currentScene = startupScene;
}
void GameManager::run() {
    init();

    ExMessage msg;
    BeginBatchDraw();  // ����˫���壬������Ļɿ��

    while (true) {
        currentScene->render();
        FlushBatchDraw();  // ÿ��ˢһ�λ�����

        if (peekmessage(&msg, EX_MOUSE)) currentScene->handleInput(msg);

        Sleep(5);  // �ɵ��ڵ� 16~30ms�����ӽ���������֡��
    }
}


void GameManager::switchToHome() { currentScene = homeScene; }
void GameManager::switchToMode1() { currentScene = mode1Scene; }
void GameManager::switchToMode2() { currentScene = mode2Scene; }
void GameManager::switchToMode3() { currentScene = mode3Scene; }
void GameManager::switchToGameScene(PlayerType opponent) {
    //gameScene = new GameScene(&res, me, opponent, [this](bool win, const string& resultText) {
    gameScene = new GameScene(&res, me, opponent, [this,opponent]() {
        this->switchToIntroScene(opponent);
        });
    gameScene->setHomeCallback([this]() {
        this->switchToHome();  // ��ȫ���ûص�
        });
    currentScene = gameScene;
}
void GameManager::switchToIntroScene(PlayerType opponent) {
    introScene = new IntroScene(&res, opponent, [this]() {
        this->switchToMode1();  
        });
    currentScene = introScene;
}


void GameManager::switchToGame2Scene(PlayerType opponent) {
    game2Scene = new Game2Scene(&res, opponent, [this]() {
        this->switchToMode2();
        });
    game2Scene->setHomeCallback([this]() {
        this->switchToHome();
        });
    currentScene = game2Scene;
}
void GameManager::switchToGame3Scene() {
    game3Scene = new Game3Scene(&res, [this]() {
        this->switchToHome();
        });
    game3Scene->setHomeCallback([this]() {
        this->switchToHome();
        });
    currentScene = game3Scene;
}
void GameManager::switchToResult(const string& text) {//��ûд Ҫչʾ��Ӧ�˵Ľ��� �˵��µĶ�����gamescene����� ����ͼҲһ����gamescene�����
    resultScene = new ResultScene(&res, text);
    currentScene = resultScene;//
}

int main() {
    GameManager game;
    game.run();
    return 0;
}
