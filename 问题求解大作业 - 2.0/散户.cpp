#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

//对小红进行初始化
void Initsanhutouzizhe(Player* sanhutouzizhe)
{
	sanhutouzizhe->choice = 1;
	sanhutouzizhe->score = 0;
	sanhutouzizhe->n = 1;
	strcpy(sanhutouzizhe->name, "sanhutouzizhe");
}

//小红进行比赛
Player* playsanhutouzizhe(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num)
{
	double qw, we, er, rt, ty;
	qw = jigoutouzizhe->score;
	we = sanhutouzizhe->score;
	er = touziguwen->score;
	rt = WaiZi->score;
	ty = NeiBu->score;
	int i = 0;
	if (sanhutouzizhe_num == 0)
	{
		return sanhutouzizhe;
	}
	else
	{
		for (i = 0; i < jigoutouzizhe_num; i++)
		{
			paly(sanhutouzizhe, jigoutouzizhe);

			hireplayer(sanhutouzizhe, jigoutouzizhe);
		}
		for (i = 0; i < sanhutouzizhe_num - 1; i++)
		{
			paly(sanhutouzizhe, sanhutouzizhe);

			hireplayer(sanhutouzizhe, sanhutouzizhe);
		}
		for (i = 0; i < touziguwen_num; i++)
		{
			paly(sanhutouzizhe, touziguwen);

			hireplayer(sanhutouzizhe, touziguwen);
		}
		for (i = 0; i < WaiZi_num; i++)
		{
			paly(sanhutouzizhe, WaiZi);

			hireplayer(sanhutouzizhe, WaiZi);
		}
		for (i = 0; i < NeiBu_num; i++)
		{
			paly(sanhutouzizhe, NeiBu);

			hireplayer(sanhutouzizhe, NeiBu);
		}
		jigoutouzizhe->score = qw;
		touziguwen->score = er;
		WaiZi->score = rt;
		NeiBu->score = ty;
	}

	return sanhutouzizhe;
	//Initjigoutouzizhe(jigoutouzizhe);
	//Initsanhutouzizhe(sanhutouzizhe);
	//Inittouziguwen(touziguwen);
	//InitWaiZi(WaiZi);
	//InitNeiBu(NeiBu);
}


