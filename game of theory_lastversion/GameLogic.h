#pragma once
#include "Player.h"

class GameLogic {
public:
    
   static void playRound(Player* me, Player* opp) {
       opp->makeChoice();
       opp->updateScore(me);
       opp->markOpponentChoice(me);
       if (opp->type == FOREIGN || opp->type == INTERNAL) {
           opp->opponentHistoryRenew();
       }
    }

   
    static bool decideWinner(Player* me, Player* opp) {
        return me->score >= opp->score;
    }
};