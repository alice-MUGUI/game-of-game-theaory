#pragma once
#define _CRT_SECUR
#include "Scene.h"


class GameManager {
public:
    vector<Player*> players;
    PlayerMe* me;
    int page;
    int mode;
    int round;
    Resource res;
    Scene* currentScene = nullptr;
    StartScene *startupScene = nullptr;
    HomeScene *homeScene = nullptr;
    Mode1Scene *mode1Scene = nullptr;
    Mode2Scene *mode2Scene = nullptr;
    Mode3Scene *mode3Scene = nullptr;
    GameScene* gameScene = nullptr;
    Game2Scene* game2Scene = nullptr;
    Game3Scene* game3Scene = nullptr;
    ResultScene *resultScene = nullptr;


    GameManager();
    ~GameManager();

    void init();
    void run(); // Ö÷Ñ­»·
    
    void switchToHome();
    void switchToMode1();
    void switchToMode2();
    void switchToMode3();
    void switchToGameScene(PlayerType opponent);
    void switchToGame2Scene(PlayerType opponent);
    void switchToGame3Scene();
    void switchToResult(const string& text);

};
