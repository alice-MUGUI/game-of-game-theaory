#include "Player.h"

void Player::reset() {
    choice = 1;
    score = 0;
    round = 1;
    opponentHistory = 1;
}

void Player::makeChoice() {
    // 默认实现，或者留空
}

void PlayerMe::makeChoice() {
    //choice = 1; // 默认合作
}


void Institutional::makeChoice() {
    choice = opponentLastestChoice;
}

void Individual::makeChoice() {
    choice = 1;
}

void Consultant::makeChoice() {
    choice = 0;
}

void Foreign::makeChoice() {
    if (opponentHistory == 0) { choice = 0; }
    else if (opponentHistory == 1) { choice = 1; }
}

void Internal::makeChoice() {
    if (round <= 4) {
        choice = round % 2;
    }
    else {
        if (opponentHistory == 0) { choice = 0; }
        else if (opponentHistory == 1) { choice = 1; }
    }
}

void Player::updateScore(Player* opponent) {
    if (choice == 1 && opponent->choice == 1) {
        score += 2;
        opponent->score += 2;
    }
    else if (choice == 0 && opponent->choice == 1) {
        score += 3;
        opponent->score -= 1;
    }
    else if (choice == 1 && opponent->choice == 0) {
        score -= 1;
        opponent->score += 3;
    }
    // 双方都选择0则不变
}

void Player::markOpponentChoice(Player* opponent) {
    opponentLastestChoice = opponent->choice;
}

void Player::opponentHistoryRenew() {
    opponentHistory = opponentHistory * opponentLastestChoice;
}

void Foreign::opponentHistoryRenew() {
    opponentHistory = opponentHistory * opponentLastestChoice;
}