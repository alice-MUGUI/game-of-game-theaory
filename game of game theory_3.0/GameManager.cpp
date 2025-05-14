#include "GameManager.h"
//#include "UIHelper.h" // 可用于封装按钮绘制
GameManager::GameManager() : page(1), mode(0) {}
GameManager::~GameManager() {
    closegraph();
}

void GameManager::init() {
    initgraph(1366, 780);
    res.loadAll(); // 加载资源
    res.BGM();
    startupScene = new StartScene(&res, [this]() { this->switchToHome(); });//传入回调函数
    homeScene = new HomeScene(&res, [this](int mode) {
    if (mode == 1) switchToMode1();
    else if (mode == 2) switchToMode2();
    else if (mode == 3) switchToMode3(); });//相当于HomeScene自带一个回调的参数，然后点击了对应区域之后，
                                            //这个回调函数就把变更的参数传回来，就实现了模式的变化
    mode1Scene = new Mode1Scene(&res, [this](PlayerType who) {//传回PlayerType
        this->switchToGameScene(who);
        });
    mode2Scene = new Mode2Scene(&res, [this](PlayerType who){
        this->switchToGame2Scene(who); 
        });//传回PlayerType
 
    mode3Scene = new Mode3Scene(&res, [this]() {
        this->switchToGame3Scene();
        });
    currentScene = startupScene;
}
void GameManager::run() {
    init();
    ExMessage msg;
    while (true) {
        currentScene->render();
        if (peekmessage(&msg, EX_MOUSE)) currentScene->handleInput(msg);
        Sleep(10);
    }
}

void GameManager::switchToHome() { currentScene = homeScene; }
void GameManager::switchToMode1() { currentScene = mode1Scene; }
void GameManager::switchToMode2() { currentScene = mode2Scene; }
void GameManager::switchToMode3() { currentScene = mode3Scene; }
void GameManager::switchToGameScene(PlayerType opponent) {
    //gameScene = new GameScene(&res, me, opponent, [this](bool win, const string& resultText) {
    gameScene = new GameScene(&res, me, opponent, [this]() {
        this->switchToHome();
        });
    currentScene = gameScene;
}
void GameManager::switchToGame2Scene(PlayerType opponent) {
    game2Scene = new Game2Scene(&res, opponent, [this]() {
        this->switchToHome();
        });
    currentScene = game2Scene;
}
void GameManager::switchToGame3Scene() {
    game3Scene = new Game3Scene(&res, [this]() {
        this->switchToHome();
        });
    currentScene = game3Scene;
}
void GameManager::switchToResult(const string& text) {//还没写 要展示对应人的介绍 人倒下的动画在gamescene里面搞 或者图也一起在gamescene里面搞
    resultScene = new ResultScene(&res, text);
    currentScene = resultScene;//
}