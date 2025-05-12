#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

void InitNeiBu(Player* NeiBu)
{
	NeiBu->choice = 1;
	NeiBu->score = 0;
	NeiBu->n = 1;
	strcpy(NeiBu->name, "NeiBu");
}

Player* playNeiBu(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num)
{
	double qw, we, er, rt, ty;
	qw = jigoutouzizhe->score;
	we = sanhutouzizhe->score;
	er = touziguwen->score;
	rt = WaiZi->score;
	ty = NeiBu->score;
	int i = 0;
	if (NeiBu_num == 0)
	{
		return NeiBu;
	}

	else
	{
		for (i = 0; i < jigoutouzizhe_num; i++)
		{
			paly(NeiBu, jigoutouzizhe);

			hireplayer(jigoutouzizhe, NeiBu);
		}
		for (i = 0; i < sanhutouzizhe_num; i++)
		{
			paly(NeiBu, sanhutouzizhe);

			hireplayer(NeiBu, sanhutouzizhe);
		}
		for (i = 0; i < touziguwen_num; i++)
		{
			paly(NeiBu, touziguwen);

			hireplayer(NeiBu, touziguwen);
		}
		for (i = 0; i < WaiZi_num; i++)
		{
			paly(NeiBu, WaiZi);

			hireplayer(NeiBu, WaiZi);
		}
		for (i = 0; i < NeiBu_num - 1; i++)
		{
			paly(NeiBu, NeiBu);

			hireplayer(NeiBu, NeiBu);
		}
		jigoutouzizhe->score = qw;
		touziguwen->score = er;
		WaiZi->score = rt;
		sanhutouzizhe->score = we;
	}
	return NeiBu;
	//Initjigoutouzizhe(jigoutouzizhe);
	//Initsanhutouzizhe(sanhutouzizhe);
	//Inittouziguwen(touziguwen);
	//InitWaiZi(WaiZi);
	//InitNeiBu(NeiBu);
}





