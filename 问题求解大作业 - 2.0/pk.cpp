#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

void mode_1_pk(ExMessage* msg) {
	int whether = 0;
	const int position = 820;
	//˼������������Ƿ��и��Ӽ��ı��������� �ܲ�����һ��A����name��Ȼ������ŵ��ظ���������ȥ->�����ƵĲ���
	rule();
	if (msg->message == WM_LBUTTONDOWN) {
		/*�������Ҫʵ�ֵĶ���
		1.��ʼ����������Ե����
		2.��ʼ��me�Ĳ������� n score
		�������ֻ�ڵ�һ�ν���ʱ���У�����Ҫ����һ����̬�ֲ��������ƴ�
		3.ÿѡ��һ�ξ�PKһ�Σ�����ѡ����pk������ ѡ��Ҫ����ڸ�λ�ò��Ұ������ pk��me��ѡ��Ҫ����¼��em����
		4.������
		5.7��֮�����ʤ��
		6.����˵���
		7.��������������
		*/
		if (t == 0) {
			Initjigoutouzizhe(jigoutouzizhe);
			Initsanhutouzizhe(sanhutouzizhe);
			Inittouziguwen(touziguwen);
			InitWaiZi(WaiZi);
			InitNeiBu(NeiBu);
			strcpy(me->name, "me");
			me->n = 1;
			me->score = 0;
			//rule();

		}
		if (t < (7 - 1))
		{
			if (isInRec(msg, 850, 720, 100, 50)) { me->choice = 1; whether = 1; t++; }
			else if (isInRec(msg, 1000, 720, 100, 50)) { me->choice = 0; whether = 1; t++; }
			if (whether) {
				if (t == 1)em = me->choice;
				switch (who)
				{
				case guwen:
				{
					palyy(me, touziguwen);
					pk_inform(touziguwen, me);
					printScore(touziguwen->score);
					printScore(me->score, position);
				}
				break;
				case jigou:
				{
					palyy(me, jigoutouzizhe);
					pk_inform(jigoutouzizhe, me);
					printScore(jigoutouzizhe->score);
					printScore(me->score, position); }
				break;
				case neibu:
				{
					palyy(me, NeiBu);
					pk_inform(NeiBu, me);
					printScore(NeiBu->score);
					printScore(me->score, position);
				}
				break;
				case waizi: {
					palyy(me, WaiZi);
					pk_inform(WaiZi, me);
					printScore(WaiZi->score);
					printScore(me->score, position);
				}
						  break;
				case sanhu: {
					palyy(me, sanhutouzizhe);
					pk_inform(sanhutouzizhe, me);
					printScore(sanhutouzizhe->score);
					printScore(me->score, position);
				}
						  break;
				}
				em = me->choice;
			}
		}
		else if (t == (7 - 1))
		{
			if (isInRec(msg, 900, 720, 50, 50)) { me->choice = 1; whether = 1; t++; }
			else if (isInRec(msg, 1000, 720, 50, 50)) { me->choice = 0; whether = 1; t++; }
			if (whether) {
				switch (who)
				{
				case guwen:
				{
					palyy(me, touziguwen);
					printScore(touziguwen->score);
					printScore(me->score, position);
					hireplayerh(me, touziguwen);
					pk_winner(touziguwen, me);
				}
				break;
				case jigou:
				{
					palyy(me, jigoutouzizhe);

					printScore(jigoutouzizhe->score);
					printScore(me->score, position);
					hireplayerh(me, jigoutouzizhe);
					pk_winner(jigoutouzizhe, me); }
				break;
				case neibu:
				{

					palyy(me, NeiBu);

					printScore(NeiBu->score);
					printScore(me->score, position);
					hireplayerh(me, NeiBu);
					pk_winner(NeiBu, me);
				}
				break;
				case waizi: {
					palyy(me, WaiZi);

					printScore(WaiZi->score);
					printScore(me->score, position);
					hireplayerh(me, WaiZi);
					pk_winner(WaiZi, me); }
						  break;
				case sanhu: {
					palyy(me, sanhutouzizhe);
					printScore(sanhutouzizhe->score);
					printScore(me->score, position);
					hireplayerh(me, sanhutouzizhe);
					pk_winner(sanhutouzizhe, me); }
						  break;
						  //page++;//����Ҫ������˵��� �����е���һ��ͼƬ�����������ͼƬ
				}
				t = 0;
				putimage(0, 0, res.img_intro + (who - 1));
				Sleep(5000);
				page = 5;
				//mode_1_start(msg);
				me->score = 0;
				who = kong;
				return;
			}
		}
	}
}

void mode_2_pk(ExMessage* msg) {
	/*������־
	1.���ð�ť ���������ģʽ ���֮��page+1
	2.���ȥ֮��������ˣ��ұ��Ǻ������ĸ��˵ķ������*/
	nl = 10;
	int x = 400, y[4] = { 200,300,400,500 }, w = 800, h = 50;
	Initjigoutouzizhe(jigoutouzizhe);
	Initsanhutouzizhe(sanhutouzizhe);
	Inittouziguwen(touziguwen);
	InitWaiZi(WaiZi);
	InitNeiBu(NeiBu);
	switch (who)
	{
	case jigou: {paly(jigoutouzizhe, sanhutouzizhe);
		hireplayer(jigoutouzizhe, sanhutouzizhe);
		printScore_1("��ɢ��pk�ķ��������", jigoutouzizhe->score, x, y[0], w, h);
		paly(jigoutouzizhe, touziguwen);
		hireplayer(jigoutouzizhe, touziguwen);
		printScore_1("�����pk�ķ��������", jigoutouzizhe->score, x, y[1], w, h);
		paly(jigoutouzizhe, WaiZi);
		hireplayer(jigoutouzizhe, WaiZi);
		printScore_1("������pk�ķ��������", jigoutouzizhe->score, x, y[2], w, h);
		paly(jigoutouzizhe, NeiBu);
		hireplayer(jigoutouzizhe, NeiBu);
		printScore_1("���ڲ�pk�ķ��������", jigoutouzizhe->score, x, y[3], w, h);
	}
			  break;
	case sanhu: {paly(sanhutouzizhe, jigoutouzizhe);
		hireplayer(sanhutouzizhe, jigoutouzizhe);
		printScore_1("�����pk�ķ��������", sanhutouzizhe->score, x, y[0], w, h);
		paly(sanhutouzizhe, touziguwen);
		hireplayer(sanhutouzizhe, touziguwen);
		printScore_1("�����pk�ķ��������", sanhutouzizhe->score, x, y[1], w, h);
		paly(sanhutouzizhe, WaiZi);
		hireplayer(sanhutouzizhe, WaiZi);
		printScore_1("������pk�ķ��������", sanhutouzizhe->score, x, y[2], w, h);
		paly(sanhutouzizhe, NeiBu);
		hireplayer(sanhutouzizhe, NeiBu);
		printScore_1("���ڲ�pk�ķ��������", sanhutouzizhe->score, x, y[3], w, h);
	}
			  break;
	case guwen: {paly(touziguwen, jigoutouzizhe);
		hireplayer(touziguwen, jigoutouzizhe);
		printScore_1("�����pk�ķ��������", touziguwen->score, x, y[0], w, h);
		paly(touziguwen, sanhutouzizhe);
		hireplayer(touziguwen, sanhutouzizhe);
		printScore_1("��ɢ��pk�ķ��������", touziguwen->score, x, y[1], w, h);
		paly(touziguwen, WaiZi);
		hireplayer(touziguwen, WaiZi);
		printScore_1("������pk�ķ��������", touziguwen->score, x, y[2], w, h);
		paly(touziguwen, NeiBu);
		hireplayer(touziguwen, NeiBu);
		printScore_1("���ڲ�pk�ķ��������", touziguwen->score, x, y[3], w, h);
	}
			  break;
	case waizi: {paly(WaiZi, jigoutouzizhe);
		hireplayer(WaiZi, jigoutouzizhe);
		printScore_1("�����pk�ķ��������", WaiZi->score, x, y[0], w, h);
		paly(WaiZi, sanhutouzizhe);
		hireplayer(WaiZi, sanhutouzizhe);
		printScore_1("��ɢ��pk�ķ��������", WaiZi->score, x, y[1], w, h);
		paly(WaiZi, touziguwen);
		hireplayer(WaiZi, touziguwen);
		printScore_1("������pk�ķ��������", WaiZi->score, x, y[2], w, h);
		paly(WaiZi, NeiBu);
		hireplayer(WaiZi, NeiBu);
		printScore_1("���ڲ�pk�ķ��������", WaiZi->score, x, y[3], w, h);
	}
			  break;
	case neibu: {paly(NeiBu, jigoutouzizhe);
		hireplayer(NeiBu, jigoutouzizhe);
		printScore_1("�����pk�ķ��������", NeiBu->score, x, y[0], w, h);
		paly(NeiBu, sanhutouzizhe);
		hireplayer(NeiBu, sanhutouzizhe);
		printScore_1("��ɢ��pk�ķ��������", NeiBu->score, x, y[1], w, h);
		paly(NeiBu, touziguwen);
		hireplayer(NeiBu, touziguwen);
		printScore_1("�����pk�ķ��������", NeiBu->score, x, y[2], w, h);
		paly(NeiBu, WaiZi);
		hireplayer(NeiBu, WaiZi);
		printScore_1("���ڲ�pk�ķ��������", NeiBu->score, x, y[3], w, h);
	}
			  break;
	}
	if (msg->message == WM_LBUTTONDOWN) {
		page = 5;
		who = kong;
		return;
	}
}

void mode_3_pk(ExMessage* msg) {
	static int ip;
	if(t==0)button(688, 700, 150, 50, "Begin");
	else button(688, 700, 150, 50, "Continue");
	if (msg->message == WM_LBUTTONDOWN) {
		if (t == 0) {
			Initjigoutouzizhe(jigoutouzizhe);
			Initsanhutouzizhe(sanhutouzizhe);
			Inittouziguwen(touziguwen);
			InitWaiZi(WaiZi);
			InitNeiBu(NeiBu);

			char fdj[100], xh[100], yt[100], hb[100], fems[100];
			if (isInRec(msg, 688, 700, 150, 50)) {
				MessageBox(GetHWnd(), _T("������λ��˳��ֱ���Ͷ�ʹ����ߡ�����Ͷ���ߡ�\n�ڲ�Ͷ���ߡ�����Ͷ���ߡ�ɢ��Ͷ����"), _T("���ǵ�������"), MB_OK);
				InputBox(yt, 100, "������Ͷ�ʹ����ߵ�����");
				InputBox(fdj, 100, "���������Ͷ���ߵ�����");
				InputBox(fems, 100, "�������ڲ�Ͷ���ߵ�����");
				InputBox(hb, 100, "����������Ͷ���ߵ�����");
				InputBox(xh, 100, "������ɢ��Ͷ���ߵ�����");
				touziguwen_num = stod(yt);
				jigoutouzizhe_num = stod(fdj);
				NeiBu_num = stod(fems);
				WaiZi_num = stod(hb);
				sanhutouzizhe_num = stod(xh);

				button(688, 700, 150, 50, "Continue");



				//�ж����������Ƿ�����
				if (NeiBu_num < 0 || sanhutouzizhe_num < 0 || touziguwen_num < 0 || WaiZi_num < 0 || jigoutouzizhe_num < 0)
				{
					MessageBox(GetHWnd(), _T("��������������Ϸ�˳�"), _T("����"), MB_OK);
					page = 4;
					mode = 0;
					exit(-1);
				}
				if (NeiBu_num == 0 && sanhutouzizhe_num == 0 && touziguwen_num == 0 && WaiZi_num == 0 && jigoutouzizhe_num == 0)
				{
					MessageBox(GetHWnd(), _T("�ţ������õ�ģʽ�����\n��Ȼ�������˶���������"), _T("��Ϸ����"), MB_OK);
					page = 4;
					mode = 0;
					exit(-1);
				}

				//��ʼ����

				char ip_1[50], nl_1[50];
				InputBox(ip_1, 50, "��������б����Ĵ�����\nÿһ�α�������С��������̭������һ����������\n");
				InputBox(nl_1, 50, "�������ִ�\n��ÿ��λͶ����pk����");
				ip = stoi(ip_1);
				nl = stoi(nl_1);
				t++;
			}
		}
		if (t <= ip)
		{
			if (isInRec(msg, 688, 700, 150, 50)) {
				Competition(jigoutouzizhe, sanhutouzizhe, touziguwen, WaiZi, NeiBu, jigoutouzizhe_num, sanhutouzizhe_num, touziguwen_num, WaiZi_num, NeiBu_num);
				printScore(touziguwen->score, 410, 180, 200, 45);
				printScore(jigoutouzizhe->score, 800, 180, 200, 45);
				printScore(NeiBu->score, 280, 650, 200, 45);
				printScore(WaiZi->score, 600, 650, 200, 45);
				printScore(sanhutouzizhe->score, 900, 650, 200, 45);
				printNum(touziguwen_num, jigoutouzizhe_num, NeiBu_num, WaiZi_num, sanhutouzizhe_num);//printNum��û��ʵ��
				//�ж������С��ɾС����
				double max, min;
				max = -1000.0;
				min = 214748364.7;

				//�ж���С

				if ((jigoutouzizhe->score < min) && (jigoutouzizhe_num != 0))
				{
					min = jigoutouzizhe->score;
				}
				if ((sanhutouzizhe->score < min) && (sanhutouzizhe_num != 0))
				{
					min = sanhutouzizhe->score;
				}
				if ((touziguwen->score < min) && (touziguwen_num != 0))
				{
					min = touziguwen->score;
				}
				if ((WaiZi->score < min) && (WaiZi_num != 0))
				{
					min = WaiZi->score;
				}
				if ((NeiBu->score < min) && (NeiBu_num != 0))
				{
					min = NeiBu->score;
				}

				//�ж���� 

				if (jigoutouzizhe->score > max)
				{
					max = jigoutouzizhe->score;
				}
				if (sanhutouzizhe->score > max)
				{
					max = sanhutouzizhe->score;
				}
				if (touziguwen->score > max)
				{
					max = touziguwen->score;
				}
				if (WaiZi->score > max)
				{
					max = WaiZi->score;
				}
				if (NeiBu->score > max)
				{
					max = NeiBu->score;
				}



				//�������С
				//����С

				if ((jigoutouzizhe->score == min) && (jigoutouzizhe_num != 0))
				{
					jigoutouzizhe_num -= 1;
				}
				if ((sanhutouzizhe->score == min) && (sanhutouzizhe_num != 0))
				{
					sanhutouzizhe_num -= 1;
				}
				if ((touziguwen->score == min) && (touziguwen_num != 0))
				{
					touziguwen_num -= 1;
				}
				if ((WaiZi->score == min) && (WaiZi_num != 0))
				{
					WaiZi_num -= 1;
				}
				if ((NeiBu->score == min) && (NeiBu_num != 0))
				{
					NeiBu_num -= 1;
				}


				//�����

				if ((jigoutouzizhe->score == max) && (jigoutouzizhe_num != 0))
				{
					jigoutouzizhe_num += 1;
					MessageBox(GetHWnd(), _T("�������Ǳ������Ӯ�ң�"), _T("������Ϸ���"), MB_OK);
				}
				if ((sanhutouzizhe->score == max) && (sanhutouzizhe_num != 0))
				{
					sanhutouzizhe_num += 1;
					MessageBox(GetHWnd(), _T("ɢ��Ͷ�����Ǳ������Ӯ�ң�"), _T("������Ϸ���"), MB_OK);
				}
				if ((touziguwen->score == max) && (touziguwen_num != 0))
				{
					touziguwen_num += 1;
					MessageBox(GetHWnd(), _T("Ͷ�ʹ������Ǳ������Ӯ�ң�"), _T("������Ϸ���"), MB_OK);
				}
				if ((WaiZi->score == max) && (WaiZi_num != 0))
				{
					WaiZi_num += 1;
					MessageBox(GetHWnd(), _T("����Ͷ�����Ǳ������Ӯ�ң�"), _T("������Ϸ���"), MB_OK);
				}
				if ((NeiBu->score == max) && (NeiBu_num != 0))
				{
					NeiBu_num += 1;
					MessageBox(GetHWnd(), _T("�ڲ�Ͷ�����Ǳ������Ӯ�ң�"), _T("������Ϸ���"), MB_OK);
				}

				t++;
				Initjigoutouzizhe(jigoutouzizhe);
				Initsanhutouzizhe(sanhutouzizhe);
				Inittouziguwen(touziguwen);
				InitWaiZi(WaiZi);
				InitNeiBu(NeiBu);
			}
			if (t > ip) {
				mode = 0;
				page = 4;
				t = 0;
				return;
			}
		}
	}
}

void pk_winner(Player* p1, Player* p2) {
	if (p1->score < p2->score) {
		putimage(280, 180, res.img_else + 8);
		putimage(280, 200, res.img_else + 0);
		Sleep(100);
		MessageBox(GetHWnd(), _T("��ϲ�㣡Ӯ���˲��ģ�"), _T("������Ϸ����"), MB_OK);
	}
	else if (p1->score > p2->score) {
		putimage(800, 180, res.img_else + 8);
		putimage(780, 200, res.img_else + 0);
		MessageBox(GetHWnd(), _T("�ٺ٣�������~"), _T("������Ϸ����"), MB_OK);
	}
}

void pk_inform(Player* p1, Player* p2) {
	if (p1->choice == 1 && p2->choice == 1) {
		MessageBox(GetHWnd(), _T("�Է�ѡ���� ��������\n���Ƕ�+2"), _T("������Ϸ���"), MB_OK);
	}
	else if (p1->choice == 1 && p2->choice == 0) {
		MessageBox(GetHWnd(), _T("�Է�ѡ���� ��������\n��+3\n�Է�-1"), _T("������Ϸ���"), MB_OK);
	}
	else if (p1->choice == 0 && p2->choice == 1) {
		MessageBox(GetHWnd(), _T("�Է�ѡ���� ����ƭ��\n��-1\n�Է�+3"), _T("������Ϸ���"), MB_OK);
	}
	else if (p1->choice == 0 && p2->choice == 0) {
		MessageBox(GetHWnd(), _T("�Է�ѡ���� ����ƭ��\n���Ƕ�+0"), _T("������Ϸ���"), MB_OK);
	}
}

void rule() {
	static int i;
	if (i == 0) {
		MessageBox(GetHWnd(), _T("��˫����ѡ����ƭ����˫���÷־�Ϊ0��\n��˫����ѡ���������˫���÷־� + 2\n�����ѡ����ƭ������ѡ�����������ҷ��� + 3�����ַ��� - 1\n�����ѡ�����������ѡ����ƭ������ҷ��� - 1, ���ַ��� + 3 "), _T("��Ϸ����"), MB_OK);
		i = 1;
	}
}


/*������־��
1.����һ����������ѡ��ĺ��� finish
2.�����ﵹ�ºͷ�����������Ļ�ϵ�bug�޸���� finish
  ������������һ��putimage ���̱������� �Լ����ܻ������֮��ķ���·����̫��
3. ���õڶ������� pk��һ�ν���˫��ѡ��ͷ��� ��Ҫ��һ����ť/��������λ�ü������� ����ppt finish
4.�����������ֵĵ�һ�źͰ�ť����*/

