#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
//初始化复读机
void Initjigoutouzizhe(Player* jigoutouzizhe)
{
	jigoutouzizhe->choice = 1;
	jigoutouzizhe->score = 0;
	jigoutouzizhe->n = 1;
	strcpy(jigoutouzizhe->name, "jigoutouzizhe");
}

//复读机进行比赛
Player* playjigoutouzizhe(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num)
{
	double qw, we, er, rt, ty;
	qw = jigoutouzizhe->score;
	we = sanhutouzizhe->score;
	er = touziguwen->score;
	rt = WaiZi->score;
	ty = NeiBu->score;
	int i = 0;
	if (jigoutouzizhe_num == 0)
	{
		return jigoutouzizhe;
	}
	else
	{
		for (i = 0; i < jigoutouzizhe_num - 1; i++)
		{
			//std::cout << "fusc" << std::endl;
			//std::cout << jigoutouzizhe->score << std::endl;

			paly(jigoutouzizhe, jigoutouzizhe);
			hireplayer(jigoutouzizhe, jigoutouzizhe);
			//std::cout << "Fusc" << std::endl;
			//std::cout << jigoutouzizhe->score << std::endl;
		}
		for (i = 0; i < sanhutouzizhe_num; i++)
		{
			//std::cout << "\n";
			//std::cout << "fusc0" << std::endl;
			//std::cout << jigoutouzizhe->score << std::endl;
			paly(jigoutouzizhe, sanhutouzizhe);

			hireplayer(jigoutouzizhe, sanhutouzizhe);
			//	std::cout << "xiao" << std::endl;
				//std::cout << sanhutouzizhe->score << std::endl;
		}
		for (i = 0; i < touziguwen_num; i++)
		{
			//std::cout << "\n";
			//std::cout << "fusc1" << std::endl;
		//	std::cout << jigoutouzizhe->score << std::endl;
			paly(jigoutouzizhe, touziguwen);

			hireplayer(jigoutouzizhe, touziguwen);
			//std::cout << "yout" << std::endl;
			//std::cout << touziguwen->score << std::endl;
		}
		for (i = 0; i < WaiZi_num; i++)
		{
			paly(jigoutouzizhe, WaiZi);

			hireplayer(jigoutouzizhe, WaiZi);
		}
		for (i = 0; i < NeiBu_num; i++)
		{
			paly(jigoutouzizhe, NeiBu);

			hireplayer(jigoutouzizhe, NeiBu);
		}

		sanhutouzizhe->score = we;
		touziguwen->score = er;
		WaiZi->score = rt;
		NeiBu->score = ty;
	}
	return jigoutouzizhe;
	//Initjigoutouzizhe(jigoutouzizhe);
	//Initsanhutouzizhe(sanhutouzizhe);
	//Inittouziguwen(touziguwen);
	//InitWaiZi(WaiZi);
	//InitNeiBu(NeiBu);
}



