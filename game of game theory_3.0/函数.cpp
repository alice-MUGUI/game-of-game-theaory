#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
int NeiBup = 0;

void isscore(Player* p1, Player* p2)//�ж�ʤ���ĺ���
{
	if (p1->choice == 1 && p2->choice == 0)
	{
		p2->score += 3;
		p1->score -= 1;
	}
	if (p2->choice == 1 && p1->choice == 0)
	{
		p1->score += 3;
		p2->score -= 1;
	}
	if (p1->choice == 1 && p2->choice == 1)
	{

		p2->score += 2;
		p1->score += 2;
	}

}

void isscores(Player* p1, Player* p2)//�ж�ʤ���ĺ���
{
	if (p1->choice == 1 && p2->choice == 0)
	{
		p2->score += 3;
		p1->score -= 1;
	}
	if (p2->choice == 1 && p1->choice == 0)
	{
		p1->score += 3;
		p2->score -= 1;
	}
	if (p1->choice == 1 && p2->choice == 1)
	{
		p2->score += 2;
		p1->score += 2;
	}

}
//���߱���

void paly(Player* p1, Player* p2)
{

	while ((p1->n <= nl) && (p2->n <= nl))
	{
		int oi, di;
		oi = p1->choice;
		di = p2->choice;

		//ʵ�ֺڰ��ϴ�ĺ���
		if (((p1->name) == (WaiZi->name)) && (di == 0) && p1->n != 1)
		{
			p1->choice = 0;
		}
		if (((p2->name) == (WaiZi->name)) && (oi == 0) && p2->n != 1)
		{
			p2->choice = 0;
		}

		//ʵ�ָ���Ħ˹����
		//�ж��Ƿ񷴻�

		if (((p1->name) == (NeiBu->name)) && ((p1->n == 2) || (p1->n == 3) || (p1->n == 4) || (p1->n == 5)))
		{
			if (di == 0)
			{
				NeiBup = 1;
			}

		}

		if (((p2->name) == (NeiBu->name)) && ((p2->n == 2) || (p2->n == 3) || (p2->n == 4) || (p2->n == 5)))
		{
			if (oi == 0)
			{
				NeiBup = 1;
			}
		}

		if (((p1->name) == (NeiBu->name)) && p1->n == 2)
		{
			p1->choice = 0;
		}
		if (((p2->name) == (NeiBu->name)) && p2->n == 2)
		{
			p2->choice = 0;
		}
		if (((p2->name) == (NeiBu->name)) && ((p2->n == 3) || (p2->n == 4)))
		{
			p2->choice = 1;
		}
		if (((p1->name) == (NeiBu->name)) && ((p1->n == 3) || (p1->n == 4)))
		{
			p1->choice = 1;
		}
		if (((p2->name) == (NeiBu->name)) && (p2->n > 4))
		{

			if (NeiBup == 1)
			{

				p2->choice = oi;
			}
			else if (NeiBup == 0)
			{
				p2->choice = 0;
			}
		}
		if (((p1->name) == (NeiBu->name)) && (p1->n > 4))
		{
			if (NeiBup == 1)
			{

				p1->choice = di;
			}
			else if (NeiBup == 0)
			{
				p1->choice = 0;
			}
		}

		//ʵ�ָ������ĺ���
		if (((p1->name) == (jigoutouzizhe->name)) && p1->n != 1)
		{
			p1->choice = di;
		}
		if (((p2->name) == (jigoutouzizhe->name)) && p2->n != 1)
		{
			p2->choice = oi;
		}


		isscore(p1, p2);


		p1->n++;
		p2->n++;
	}
}

void palyy(Player* p1, Player* p2)
{



	//ʵ�ָ���Ħ˹����
	//�ж��Ƿ񷴻�
	if (((p2->name) == (NeiBu->name)) && ((p2->n == 2) || (p2->n == 3) || (p2->n == 4) || (p2->n == 1)))
	{
		if (em == 0)
		{
			NeiBup = 1;
		}
	}


	if (((p2->name) == (NeiBu->name)) && p2->n == 2)
	{
		p2->choice = 0;
	}
	if ((p2->name) == (NeiBu->name) && ((p2->n == 3) || (p2->n == 4)))
	{
		p2->choice = 1;
	}


	if ((p2->name) == (NeiBu->name) && (p2->n > 4))
	{

		if (NeiBup == 1)
		{

			p2->choice = em;
		}
		else if (NeiBup == 0)
		{
			p2->choice = 0;
		}
	}


	if ((p2->name) == (jigoutouzizhe->name) && p2->n == 1)
	{
		p2->choice = 1;
	}

	if ((p2->name) == (jigoutouzizhe->name) && p2->n != 1)
	{
		p2->choice = em;
	}//ʵ�ָ������ĺ���


	//ʵ�ֺڰ��ϴ�ĺ���

	if ((p2->name) == (WaiZi->name) && (em == 0))
	{
		p2->choice = 0;
	}
	isscores(p1, p2);


	p1->n++;
	p2->n++;

}
//��ӡҳ��

void menu(int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num)
{

	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "---------------������: " << jigoutouzizhe_num << "-------------------С��: " << sanhutouzizhe_num << "-----------------\n";
	std::cout << "---------------����: " << touziguwen_num << " --------------------�ڰ�: " << WaiZi_num << "------------------\n";
	std::cout << "---------------����Ħ˹: " << NeiBu_num << "------------------------------------------ \n";
	std::cout << "--------------------------------------------------------------------\n";


}

//����
void Competition(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num)
{


	playjigoutouzizhe(jigoutouzizhe, sanhutouzizhe, touziguwen, WaiZi, NeiBu, jigoutouzizhe_num, sanhutouzizhe_num, touziguwen_num, WaiZi_num, NeiBu_num);
	playsanhutouzizhe(jigoutouzizhe, sanhutouzizhe, touziguwen, WaiZi, NeiBu, jigoutouzizhe_num, sanhutouzizhe_num, touziguwen_num, WaiZi_num, NeiBu_num);
	playtouziguwen(jigoutouzizhe, sanhutouzizhe, touziguwen, WaiZi, NeiBu, jigoutouzizhe_num, sanhutouzizhe_num, touziguwen_num, WaiZi_num, NeiBu_num);
	playWaiZi(jigoutouzizhe, sanhutouzizhe, touziguwen, WaiZi, NeiBu, jigoutouzizhe_num, sanhutouzizhe_num, touziguwen_num, WaiZi_num, NeiBu_num);
	playNeiBu(jigoutouzizhe, sanhutouzizhe, touziguwen, WaiZi, NeiBu, jigoutouzizhe_num, sanhutouzizhe_num, touziguwen_num, WaiZi_num, NeiBu_num);

}
void hireplayer(Player* p1, Player* p2)
{
	if ((p1->name) == (jigoutouzizhe->name))
	{
		p1->choice = 1;
	}
	if ((p2->name) == (jigoutouzizhe->name))
	{
		p2->choice = 1;
	}
	if ((p2->name) == (WaiZi->name))
	{
		p2->choice = 1;
	}
	if ((p1->name) == (WaiZi->name))
	{
		p1->choice = 1;
	}
	p1->n = 1;
	p2->n = 1;
	if ((p1->name) == (NeiBu->name))
	{
		p1->choice = 1;

		NeiBup = 0;
	}
	if ((p2->name) == (NeiBu->name))
	{
		p2->choice = 1;
		NeiBup = 0;
	}

}

void hireplayerh(Player* p1, Player* p2)
{

	if ((p2->name) == (jigoutouzizhe->name))
	{
		p2->choice = 1;
	}
	if ((p2->name) == (WaiZi->name))
	{
		p2->choice = 1;
	}

	p1->n = 1;
	p2->n = 1;

	if ((p2->name) == (NeiBu->name))
	{
		p2->choice = 1;
		NeiBup = 0;
	}

}


