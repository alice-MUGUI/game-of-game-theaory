#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

//对油条进行初始化
void Inittouziguwen(Player* touziguwen)
{
	touziguwen->choice = 0;
	touziguwen->score = 0;
	touziguwen->n = 1;
	strcpy(touziguwen->name, "touziguwen");

}

//油条进行比赛
Player* playtouziguwen(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num)
{
	double qw, we, er, rt, ty;
	qw = jigoutouzizhe->score;
	we = sanhutouzizhe->score;
	er = touziguwen->score;
	rt = WaiZi->score;
	ty = NeiBu->score;
	int i = 0;
	if (touziguwen_num == 0)
	{
		return touziguwen;
	}

	else
	{
		for (i = 0; i < jigoutouzizhe_num; i++)
		{
			paly(touziguwen, jigoutouzizhe);

			hireplayer(touziguwen, jigoutouzizhe);
		}
		for (i = 0; i < sanhutouzizhe_num; i++)
		{
			paly(touziguwen, sanhutouzizhe);

			hireplayer(touziguwen, sanhutouzizhe);
		}
		for (i = 0; i < touziguwen_num - 1; i++)
		{
			paly(touziguwen, touziguwen);

			hireplayer(touziguwen, touziguwen);
		}
		for (i = 0; i < WaiZi_num; i++)
		{
			paly(touziguwen, WaiZi);

			hireplayer(touziguwen, WaiZi);
		}
		for (i = 0; i < NeiBu_num; i++)
		{
			paly(touziguwen, NeiBu);

			hireplayer(touziguwen, NeiBu);
		}
		jigoutouzizhe->score = qw;
		sanhutouzizhe->score = we;
		WaiZi->score = rt;
		NeiBu->score = ty;
	}

	return touziguwen;
	//Initjigoutouzizhe(jigoutouzizhe);
	//Initsanhutouzizhe(sanhutouzizhe);
	//Inittouziguwen(touziguwen);
	//InitWaiZi(WaiZi);
	//InitNeiBu(NeiBu);
}


