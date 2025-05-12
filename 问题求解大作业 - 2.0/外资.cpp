#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
//对黑帮进行初始化
void InitWaiZi(Player* WaiZi)
{
	WaiZi->choice = 1;
	WaiZi->score = 0;
	WaiZi->n = 1;
	strcpy(WaiZi->name, "WaiZi");
}
//黑帮进行比赛
Player* playWaiZi(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num)
{
	double qw, we, er, rt, ty;
	qw = jigoutouzizhe->score;
	we = sanhutouzizhe->score;
	er = touziguwen->score;
	rt = WaiZi->score;
	ty = NeiBu->score;
	int i = 0;
	if (WaiZi_num == 0)
	{
		return WaiZi;
	}

	else
	{
		for (i = 0; i < jigoutouzizhe_num; i++)
		{
			paly(WaiZi, jigoutouzizhe);

			hireplayer(jigoutouzizhe, WaiZi);
		}
		for (i = 0; i < sanhutouzizhe_num; i++)
		{
			paly(WaiZi, sanhutouzizhe);

			hireplayer(WaiZi, sanhutouzizhe);
		}
		for (i = 0; i < touziguwen_num; i++)
		{
			paly(WaiZi, touziguwen);
			hireplayer(WaiZi, touziguwen);
		}
		for (i = 0; i < WaiZi_num - 1; i++)
		{
			paly(WaiZi, WaiZi);
			hireplayer(WaiZi, WaiZi);
		}
		for (i = 0; i < NeiBu_num; i++)
		{
			paly(WaiZi, NeiBu);

			hireplayer(WaiZi, NeiBu);
		}
		jigoutouzizhe->score = qw;
		touziguwen->score = er;
		sanhutouzizhe->score = we;
		NeiBu->score = ty;
	}
	return WaiZi;
	//Initjigoutouzizhe(jigoutouzizhe);
	//Initsanhutouzizhe(sanhutouzizhe);
	//Inittouziguwen(touziguwen);
	//InitWaiZi(WaiZi);
	//InitNeiBu(NeiBu);
}


