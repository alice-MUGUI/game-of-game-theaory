#include "Scene.h"

StartScene::StartScene(Resource* r, std::function<void()> callback)
    : page(0), res(r), onFinish(callback) {}

void StartScene::render() {
    putimage(0, 0, res->img_start + page);
    drawButton(600, 600, 200, 60, "��ʼ��Ϸ");
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
    drawButton(200, 90, 300, 75, "��������");
    drawButton(200, 220, 300, 75, "��������");
    drawButton(200, 350, 300, 75, "�г�����");
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
    drawButton(341, 520, 200, 50, "1��Ͷ����");
    drawButton(797, 520, 200, 50, "2��Ͷ����");
    drawButton(114, 680, 200, 50, "3��Ͷ����");
    drawButton(569, 680, 200, 50, "4��Ͷ����");
    drawButton(1024, 680, 200, 50, "5��Ͷ����");
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
        opponent = new Player(PlayerType::HUMAN, "δ֪Ͷ����");
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
    drawButton(850, 720, 100, 50, "����");
    drawButton(1000, 720, 100, 50, "��ƭ");

    char buf[100];
    sprintf(buf, "�غ� %d / 7", round + 1);
    outtextxy(600, 50, buf);
    outtextxy(300, 100, buf);
    const int position = 820;
    printScore(opponent->score);
    printScore(me->score, position);
}//û������

void GameScene::tellResult(Player* me, Player* opponent) {
    if (opponent->choice == 1 && me->choice == 1) {
        MessageBox(GetHWnd(), _T("�Է�ѡ���� ��������\n���Ƕ�+2"), _T("������Ϸ���"), MB_OK);
    }
    else if (opponent->choice == 1 && me->choice == 0) {
        MessageBox(GetHWnd(), _T("�Է�ѡ���� ��������\n��+3\n�Է�-1"), _T("������Ϸ���"), MB_OK);
    }
    else if (opponent->choice == 0 && me->choice == 1) {
        MessageBox(GetHWnd(), _T("�Է�ѡ���� ����ƭ��\n��-1\n�Է�+3"), _T("������Ϸ���"), MB_OK);
    }
    else if (opponent->choice == 0 && me->choice == 0) {
        MessageBox(GetHWnd(), _T("�Է�ѡ���� ����ƭ��\n���Ƕ�+0"), _T("������Ϸ���"), MB_OK);
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

            if (round == 0) em = me->choice;//�õ����ҵ�ѡ�񣬴��뺯���õ��Է���ѡ��
            GameLogic::playRound(me, opponent);
            //�����Ѿ������ѡ�񡢷������¡���Ϣ��¼
            //Ȼ����ɽ���Ĵ�ӡ
            tellResult(me, opponent);
            round++;

            if (round == 7) {
                tellResult(me, opponent);
                bool win = GameLogic::decideWinner(me, opponent);
                if (win) {
                    putimage(280, 180, res->img_else + 8);
                    putimage(280, 200, res->img_else + 0);
                    Sleep(100);
                    MessageBox(GetHWnd(), _T("��ϲ�㣡Ӯ���˲��ģ�"), _T("������Ϸ����"), MB_OK);
                }
                else {
                    putimage(800, 180, res->img_else + 8);
                    putimage(780, 200, res->img_else + 0);
                    MessageBox(GetHWnd(), _T("�ٺ٣�������~"), _T("������Ϸ����"), MB_OK);
                }
                onGameEnd();//
            }
        }
    }
}

void Mode2Scene::render() {
    BeginBatchDraw();
    putimage(0, 0, res->img_bk + 2);
    drawButton(341, 520, 200, 50, "����Ͷ����");
    drawButton(797, 520, 200, 50, "����Ͷ����");
    drawButton(114, 680, 200, 50, "�ڲ�Ͷ����");
    drawButton(569, 680, 200, 50, "����Ͷ����");
    drawButton(1024, 680, 200, 50, "ɢ��Ͷ����");
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
    // ��ʼ��4�����֣��ų��Լ���
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
        me = new Player(PlayerType::HUMAN, "δ֪Ͷ����");
        break;
    }

    opponentLabels.clear();
    resultScores.clear();

    for (int i = 0; i < 4; ++i) {
        opponents[i]->reset();
        me->reset();
        GameLogic::playRound(me, opponents[i]);
        resultScores.push_back(me->score);

        string label = "��" + opponents[i]->name + "pk�ķ��������";
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
    drawButton(1000, 650, 200, 60, "������ҳ", RGB(255, 100, 100));
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
    // ����ʱ����ʼ����ң��ȴ���ť�����������
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

    // �������������ս nl ��
    for (size_t i = 0; i < players.size(); ++i) {
        for (size_t j = i + 1; j < players.size(); ++j) {
            for (int r = 0; r < matchPerPair; ++r) {
                GameLogic::playRound(players[i], players[j]);
            }
        }
    }

    // ͳ�������С����
    double maxScore = -1e9, minScore = 1e9;
    for (auto& p : players) {
        maxScore = max(maxScore, p->score);
        minScore = min(minScore, p->score);
    }

    // ��̭��С���������
    for (size_t i = 0; i < players.size(); ++i) {
        if (players[i]->score == maxScore && playerCounts[i] > 0) {
            ++playerCounts[i];
            string msg = players[i]->name + " �Ǳ������Ӯ�ң�";
            MessageBoxA(GetHWnd(), msg.c_str(), "���Ľ��", MB_OK);
        }
        if (players[i]->score == minScore && playerCounts[i] > 0) {
            --playerCounts[i];
        }
    }

    currentRound++;

    if (currentRound >= totalRounds) {
        MessageBox(GetHWnd(), _T("�г����Ľ�������Ϸ�ص���ҳ"), _T("���"), MB_OK);
        onFinish();
    }
    else {
        initPlayers(); // ������һ��ǰ���³�ʼ�����
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
            MessageBox(GetHWnd(), _T("������λ��˳��ֱ���Ͷ�ʹ����ߡ�����Ͷ���ߡ�\n�ڲ�Ͷ���ߡ�����Ͷ���ߡ�ɢ��Ͷ����"), _T("���ǵ�������"), MB_OK);

            char buf[100];
            InputBox(buf, 100, "������Ͷ�ʹ����ߵ�����"); playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "���������Ͷ���ߵ�����"); playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "�������ڲ�Ͷ���ߵ�����"); playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "����������Ͷ���ߵ�����");  playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "������ɢ��Ͷ���ߵ�����");  playerCounts.push_back(stoi(buf));
            InputBox(buf, 100, "���������������");          totalRounds = stoi(buf);
            InputBox(buf, 100, "������ÿ�Բ����߶�ս����");    matchPerPair = stoi(buf);

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

}//����ʱ������������㶯�� ����handle���ؽ��档
//������ʱ����Result���棬����ʱֱ�ӷ���home����Ҫ����������GameManager�е���