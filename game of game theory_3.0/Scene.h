#pragma once
#include "Resource.h"
#include "UIHelper.h"
#include "GameLogic.h"
#include <functional>
#include <vector>
#include <algorithm>


class Scene {
public:
    virtual void render() = 0;              // 渲染界面内容
    virtual void handleInput(ExMessage msg) = 0;  // 响应鼠标点击等
    virtual ~Scene() = default;
};

class StartScene : public Scene {
private:
    int page;
    Resource* res;
    std::function<void()> onFinish;
public:
    StartScene(Resource* r, std::function<void()> callback);
    void render() override;
    void handleInput(ExMessage msg) override;
};

class HomeScene : public Scene {
private:
    Resource* res;
    std::function<void(int)> onModeSelected;

public:
    HomeScene(Resource* r, std::function<void(int)> callback);
    void render() override;
    void handleInput(ExMessage msg) override;
};

class Mode1Scene : public Scene {
private:
    Resource* res;
    function<void(PlayerType)> onSelect;//Mode1对应的回传函数是onSelect

public:
    Mode1Scene(Resource* r, function<void(PlayerType)> callback) : res(r), onSelect(callback) {}

    void render() override;

    void handleInput(ExMessage msg) override;
};

class GameScene : public Scene {
private:
    Resource* res;
    Player* me;
    Player* opponent;
    PlayerType opponentType;
    int round = 0;
    int em = 1;
    //function<void(bool, string)> onGameEnd;
    function<void()> onGameEnd;

public:
    //GameScene(Resource* r, Player* player, PlayerType enemy, function<void(bool, string)> callback);
    GameScene(Resource* r, Player* player, PlayerType enemy, function<void()> callback);
    void render() override;
    void tellResult(Player* me, Player* opponent);
    void handleInput(ExMessage msg) override;
};

class Mode2Scene : public Scene {
private:
    Resource* res;
    function<void(PlayerType)> onSelect;

public:
    Mode2Scene(Resource* r, function<void(PlayerType)> callback) : res(r), onSelect(callback) {}

    void render() override;

    void handleInput(ExMessage msg) override;
};

class Game2Scene : public Scene {
private:
private:
    Resource* res;
    Player* me;//是统一用了Player指针
    Player* opponents[4];
    PlayerType opponentType;
    function<void()> onGameEnd;
    vector<string> opponentLabels;
    vector<double> resultScores;

public:
    Game2Scene(Resource* r, PlayerType type, function<void()> callback);
    void render() override;
    void handleInput(ExMessage msg) override;
};

class Mode3Scene : public Scene {
private:
    Resource* res;
    function<void()> onBegin;

public:
    Mode3Scene(Resource* r, function<void()> callback) : res(r), onBegin(callback) {}

    void render() override;

    void handleInput(ExMessage msg) override;
};

class Game3Scene : public Scene {
private:
    Resource* res;
    int totalRounds = 0;
    int currentRound = 0;
    int matchPerPair = 0;

    std::vector<Player*> players;
    std::vector<int> playerCounts;

    bool inputFinished = false;
    std::function<void()> onFinish;

    void initPlayers();
    void simulateCompetition();

public:
    Game3Scene(Resource* r, std::function<void()> callback);
    ~Game3Scene();

    void render() override;
    void handleInput(ExMessage msg) override;
};

class ResultScene : public Scene {
private:
    Resource* res;
    string result;

public:
    ResultScene(Resource* r, const string& rText) : res(r), result(rText) {}
    void render() override;
    void handleInput(ExMessage msg) override {}
};