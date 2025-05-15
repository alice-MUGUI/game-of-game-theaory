#pragma once
#include <string>
using namespace std;

enum PlayerType {
    CONSULTANT=1,
    INSTITUTIONAL,
    INTERNAL,
    FOREIGN,
    INDIVIDUAL,        
    HUMAN
};

class Player {
private:
    int x, y; // ��ʾλ��

public:
    PlayerType type;
    string name;
    int choice;
    double score;
    int round;
    int opponentLastestChoice;
    int opponentHistory;

    Player(PlayerType t = HUMAN, const string& n = "���", double s = 0) 
        : type(t), name(n), choice(1), score(s), round(1) {};

    void reset();
    virtual void makeChoice();
    void updateScore(Player* opponent);
    void markOpponentChoice(Player* opponent);
    virtual void opponentHistoryRenew();
};

class PlayerMe : public Player {
public:
    PlayerMe() :Player(PlayerType::HUMAN) {};
    virtual void makeChoice();
};

class Institutional : public Player {
public:
    Institutional():Player(INSTITUTIONAL, "����Ͷ����") {};
    virtual void makeChoice();
};

class Individual : public Player {
public:
    Individual() :Player(INDIVIDUAL, "ɢ��") {};
    virtual void makeChoice();
};

class Consultant : public Player {
public:
    Consultant() :Player(CONSULTANT, "����") {};
    virtual void makeChoice();
};

class Foreign : public Player {
public:
    Foreign() :Player(FOREIGN, "���Ͷ����") { opponentHistory = 1; };
    virtual void opponentHistoryRenew();
    virtual void makeChoice();
};

class Internal : public Foreign {
public:
    Internal(PlayerType t = INTERNAL, const string& n = "�ڲ�Ͷ����") :Foreign() {
        type = t;
        name = n;
    };
    
    virtual void makeChoice();
};