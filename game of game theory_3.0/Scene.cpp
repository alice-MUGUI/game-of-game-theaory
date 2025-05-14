#include "Scene.h"

StartScene::StartScene(Resource* r, std::function<void()> callback)
    : page(0), res(r), onFinish(callback) {}

void StartScene::render() {
    putimage(0, 0, res->img_start + page);
    drawButton(600, 600, 200, 60, "开始游戏");
}

void StartScene::handleInput(ExMessage msg) {
    if (msg.message == WM_LBUTTONDOWN) {
        ++page;
        if (page >= 4) {
            onFinish();
        }
    }
}

HomeScene::HomeScene(Resource* r,std::function<void(int)> callback)
    :res(r), onModeSelected(callback) {}

void HomeScene::render() {
    putimage(0, 0, res->img_start + 4);
    drawButton(200, 90, 300, 75, "我来博弈");
    drawButton(200, 220, 300, 75, "两两博弈");
    drawButton(200, 350, 300, 75, "市场博弈");
}

void HomeScene::handleInput(ExMessage msg) {
    if (msg.message == WM_LBUTTONDOWN) {
        if (isInRect(&msg, 200, 90, 300, 75)) {
            onModeSelected(1);
        }
        else if (isInRect(&msg, 200, 220, 300, 75)) {
            onModeSelected(2);
        }
        else if (isInRect(&msg, 200, 350, 300, 75)) {
            onModeSelected(3);
        }
    }
}

void Mode1Scene::render() {
    BeginBatchDraw();
    putimage(0, 0, res->img_bk + 1);
    drawButton(341, 520, 200, 50, "1号投资者");
    drawButton(797, 520, 200, 50, "2号投资者");
    drawButton(114, 680, 200, 50, "3号投资者");
    drawButton(569, 680, 200, 50, "4号投资者");
    drawButton(1024, 680, 200, 50, "5号投资者");
    drawButton(0, 0, 150, 50, "home");
    EndBatchDraw();
}

void Mode1Scene::handleInput(ExMessage msg) {
    if (msg.message == WM_LBUTTONDOWN) {
        if (isInRect(&msg, 341, 520, 200, 50)) onSelect(PlayerType::CONSULTANT);
        else if (isInRect(&msg, 797, 520, 200, 50)) onSelect(PlayerType::INSTITUTIONAL);
        else if (isInRect(&msg, 114, 680, 200, 50)) onSelect(PlayerType::INTERNAL);
        else if (isInRect(&msg, 569, 680, 200, 50)) onSelect(PlayerType::FOREIGN);
        else if (isInRect(&msg, 1024, 680, 200, 50)) onSelect(PlayerType::INDIVIDUAL);
    }
}//look here

//GameScene::GameScene(Resource* r, Player* player, PlayerType type, function<void(bool, string)> callback)
GameScene::GameScene(Resource* r, Player* player, PlayerType type, function<void()> callback)
    : res(r), me(player), opponentType(type), onGameEnd(callback) {
    switch (opponentType) {
    case PlayerType::CONSULTANT:
        opponent = new Consultant();
        break;
    case PlayerType::INSTITUTIONAL:
        opponent = new Institutional();
        break;
    case PlayerType::INTERNAL:
        opponent = new Internal();
        break;
    case PlayerType::FOREIGN:
        opponent = new Foreign();
        break;
    case PlayerType::INDIVIDUAL:
        opponent = new Individual();
        break;
    default:
        opponent = new Player(PlayerType::HUMAN, "未知投资者");
        break;
    }
    opponent->reset();
    me->reset();
    round = 0;
 }


void GameScene::render() {
    putimage(0, 0, res->img_bk + 0);
    putimage(0, 0, res->img_bk + 4);
    putimage(280, 180, res->img_else + static_cast<int>(opponentType));
    putimage(800, 180, res->img_else + 6);
    drawButton(850, 720, 100, 50, "合作");
    drawButton(1000, 720, 100, 50, "欺骗");

    char buf[100];
    sprintf(buf, "回合 %d / 7", round + 1);
    outtextxy(600, 50, buf);
    outtextxy(300, 100, buf);
    const int position = 820;
    printScore(opponent->score);
    printScore(me->score, position);
}//没问题了

void GameScene::tellResult(Player* me, Player* opponent) {
    if (opponent->choice == 1 && me->choice == 1) {
        MessageBox(GetHWnd(), _T("对方选择了 【合作】\n你们都+2"), _T("本次游戏结果"), MB_OK);
    }
    else if (opponent->choice == 1 && me->choice == 0) {
        MessageBox(GetHWnd(), _T("对方选择了 【合作】\n你+3\n对方-1"), _T("本次游戏结果"), MB_OK);
    }
    else if (opponent->choice == 0 && me->choice == 1) {
        MessageBox(GetHWnd(), _T("对方选择了 【欺骗】\n你-1\n对方+3"), _T("本次游戏结果"), MB_OK);
    }
    else if (opponent->choice == 0 && me->choice == 0) {
        MessageBox(GetHWnd(), _T("对方选择了 【欺骗】\n你们都+0"), _T("本次游戏结果"), MB_OK);
    }
}

void GameScene::handleInput(ExMessage msg) {
    if (msg.message == WM_LBUTTONDOWN) {
        if (round < 7) {
            if (isInRect(&msg, 850, 720, 100, 50)) {
                me->choice = 1;
            }
            else if (isInRect(&msg, 1000, 720, 100, 50)) {
                me->choice = 0;
            }
            else {
                return;
            }

            if (round == 0) em = me->choice;//得到了我的选择，传入函数得到对方的选择
            GameLogic::playRound(me, opponent);
            //现在已经完成了选择、分数更新、信息记录
            //然后完成界面的打印
            tellResult(me, opponent);
            round++;

            if (round == 7) {
                tellResult(me, opponent);
                bool win = GameLogic::decideWinner(me, opponent);
                if (win) {
                    putimage(280, 180, res->img_else + 8);
                    putimage(280, 200, res->img_else + 0);
                    Sleep(100);
                    MessageBox(GetHWnd(), _T("恭喜你！赢得了博弈！"), _T("本轮游戏结束"), MB_OK);
                }
                else {
                    putimage(800, 180, res->img_else + 8);
                    putimage(780, 200, res->img_else + 0);
                    MessageBox(GetHWnd(), _T("嘿嘿，你输啦~"), _T("本轮游戏结束"), MB_OK);
                }
                onGameEnd();//
            }
        }
    }
}

void Mode2Scene::render() {
    BeginBatchDraw();
    putimage(0, 0, res->img_bk + 2);
    drawButton(341, 520, 200, 50, "顾问投资者");
    drawButton(797, 520, 200, 50, "机构投资者");
    drawButton(114, 680, 200, 50, "内部投资者");
    drawButton(569, 680, 200, 50, "外资投资者");
    drawButton(1024, 680, 200, 50, "散户投资者");
    drawButton(0, 0, 150, 50, "home");
    EndBatchDraw();
}

void Mode2Scene::handleInput(ExMessage msg) {
    if (msg.message == WM_LBUTTONDOWN) {
        if (isInRect(&msg, 341, 520, 200, 50)) onSelect(PlayerType::CONSULTANT);
        else if (isInRect(&msg, 797, 520, 200, 50)) onSelect(PlayerType::INSTITUTIONAL);
        else if (isInRect(&msg, 114, 680, 200, 50)) onSelect(PlayerType::INTERNAL);
        else if (isInRect(&msg, 569, 680, 200, 50)) onSelect(PlayerType::FOREIGN);
        else if (isInRect(&msg, 1024, 680, 200, 50)) onSelect(PlayerType::INDIVIDUAL);
    }
}

Game2Scene::Game2Scene(Resource* r, PlayerType type, function<void()> callback)
    : res(r), opponentType(type), onGameEnd(callback) {
    // 初始化4个对手（排除自己）
    int idx = 0;
    if (type != INSTITUTIONAL) opponents[idx++] = new Institutional();
    if (type != INDIVIDUAL)    opponents[idx++] = new Individual();
    if (type != CONSULTANT)    opponents[idx++] = new Consultant();
    if (type != FOREIGN)       opponents[idx++] = new Foreign();
    if (type != INTERNAL)      opponents[idx++] = new Internal();

    switch (type) {
    case PlayerType::CONSULTANT:
        me = new Consultant();
        break;
    case PlayerType::INSTITUTIONAL:
        me = new Institutional();
        break;
    case PlayerType::INTERNAL:
        me = new Internal();
        break;
    case PlayerType::FOREIGN:
        me = new Foreign();
        break;
    case PlayerType::INDIVIDUAL:
        me = new Individual();
        break;
    default:
        me = new Player(PlayerType::HUMAN, "未知投资者");
        break;
    }

    opponentLabels.clear();
    resultScores.clear();

    for (int i = 0; i < 4; ++i) {
        opponents[i]->reset();
        me->reset();
        GameLogic::playRound(me, opponents[i]);
        resultScores.push_back(me->score);

        string label = "与" + opponents[i]->name + "pk的分数结果：";
        opponentLabels.push_back(label);
    }
}

void Game2Scene::render() {
    putimage(0, 0, res->img_bk + 5);
    int x = 400, w = 800, h = 50;
    int y[4] = { 200, 300, 400, 500 };
    for (int i = 0; i < 4; ++i) {
        printScore_1(opponentLabels[i].c_str(), resultScores[i], x, y[i], w, h, RGB(200, 200, 255));
    }
    drawButton(1000, 650, 200, 60, "返回主页", RGB(255, 100, 100));
}

void Game2Scene::handleInput(ExMessage msg) {
    if (msg.message == WM_LBUTTONDOWN) {
        if (isInRect(&msg, 1000, 650, 200, 60)) {
            onGameEnd();
        }
    }
}


void Mode3Scene::render(){
    putimage(0, 0, res->img_bk + 3);
    drawButton(0, 0, 150, 50, "home");
    drawButton(688, 700, 150, 50, "Begin");
}

void Mode3Scene::handleInput(ExMessage msg)  {
    if (msg.message == WM_LBUTTONDOWN && isInRect(&msg, 688, 700, 150, 50)) {
        onBegin();
    }
}

Game3Scene::Game3Scene(Resource* r, std::function<void()> callback)
    : res(r), onFinish(callback) {
    // 构造时不初始化玩家，等待按钮点击触发输入
}

Game3Scene::~Game3Scene() {
    for (auto p : players) delete p;
}

void Game3Scene::initPlayers() {
    players.clear();
    players.push_back(new Consultant());
    players.push_back(new Institutional());
    players.push_back(new Internal());
    players.push_back(new Foreign());
    players.push_back(new Individual());
    for (auto p : players) p->reset();
}

void Game3Scene::simulateCompetition() {
    for (auto& p : players) p->reset();

    // 所有玩家两两对战 nl 次
    for (size_t i = 0; i < players.size(); ++i) {
        for (size_t j = i + 1; j < players.size(); ++j) {
            for (int r = 0; r < matchPerPair; ++r) {
                GameLogic::playRound(players[i], players[j]);
            }
        }
    }

    // 统计最大最小分数
    double maxScore = -1e9, minScore = 1e9;
    for (auto& p : players) {
        maxScore = max(maxScore, p->score);
        minScore = min(minScore, p->score);
    }

    // 淘汰最小，补充最大
    for (size_t i = 0; i < players.size(); ++i) {
        if (players[i]->score == maxScore && playerCounts[i] > 0) {
            ++playerCounts[i];
            string msg = players[i]->name + " 是本轮最大赢家！";
            MessageBoxA(GetHWnd(), msg.c_str(), "博弈结果", MB_OK);
        }
        if (players[i]->score == minScore && playerCounts[i] > 0) {
            --playerCounts[i];
        }
    }

    currentRound++;

    if (currentRound >= totalRounds) {
        MessageBox(GetHWnd(), _T("市场博弈结束，游戏回到首页"), _T("完成"), MB_OK);
        onFinish();
    }
    else {
        initPlayers(); // 进入下一轮前重新初始化玩家
    }
}

void Game3Scene::render() {
    putimage(0, 0, res->img_bk + 6);
    const int yBase = 180;
    const int xStart[5] = { 400, 800, 280, 600, 900 };
    const int yLine[5] = { yBase, yBase, 650, 650, 650 };

    for (int i = 0; i < 5; ++i) {
        printScore(players[i]->score, xStart[i], yLine[i], 200, 45);
    }

    printNum(playerCounts[0], playerCounts[1], playerCounts[2], playerCounts[3], playerCounts[4]);

    drawButton(688, 700, 150, 50, currentRound == 0 ? "Begin" : "Continue");
}

void Game3Scene::handleInput(ExMessage msg) {
    if (msg.message == WM_LBUTTONDOWN && isInRect(&msg, 688, 700, 150, 50)) {
        if (!inputFinished) {
            MessageBox(GetHWnd(), _T("他们五位按顺序分别是投资顾问者、机构投资者、\n内部投资者、外资投资者、散户投资者"), _T("还记得他们吗？"), MB_OK);

            char buf[100];
            InputBox(buf, 100, "请输入投资顾问者的数量"); playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "请输入机构投资者的数量"); playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "请输入内部投资者的数量"); playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "请输入外资投资者的数量");  playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "请输入散户投资者的数量");  playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "请输入比赛总轮数");          totalRounds = stoi(buf);
            InputBox(buf, 100, "请输入每对博弈者对战次数");    matchPerPair = stoi(buf);

            initPlayers();
            inputFinished = true;
        }
        else {
            simulateCompetition();
        }
    }
}

void ResultScene::render(){
    const int position = 820;
    //printScore(touziguwen->score);
    //printScore(me->score, position);
    putimage(0, 0, res->img_bk + 4);
    outtextxy(400, 300, result.c_str());

}//若有时间可以制作结算动画 再用handle返回界面。
//现在暂时不用Result界面，先暂时直接返回home，若要调整可以在GameManager中调整