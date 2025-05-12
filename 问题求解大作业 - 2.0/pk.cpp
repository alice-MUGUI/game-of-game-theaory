#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

void mode_1_pk(ExMessage* msg) {
	int whether = 0;
	const int position = 820;
	//思考：这个部分是否有更加简洁的表述方法捏 能不能用一个A代替name，然后把他放到重复的内容中去->待完善的部分
	rule();
	if (msg->message == WM_LBUTTONDOWN) {
		/*这个部分要实现的东西
		1.初始化几个会面对的玩家
		2.初始化me的部分数据 n score
		以上两项都只在第一次进入时运行，所以要设置一个静态局部变量来计次
		3.每选择一次就PK一次：所以选择是pk的条件 选择要鼠标在该位置并且按下左键 pk完me的选择要被记录在em当中
		4.输出结果
		5.7次之后决出胜负
		6.输的人倒下
		7.进入介绍人物界面
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
						  //page++;//所以要让输的人倒下 并且切到下一张图片（介绍人物的图片
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
	/*工作日志
	1.设置按钮 五个人五种模式 点击之后page+1
	2.点进去之后左边是人，右边是和另外四个人的分数结果*/
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
		printScore_1("与散户pk的分数结果：", jigoutouzizhe->score, x, y[0], w, h);
		paly(jigoutouzizhe, touziguwen);
		hireplayer(jigoutouzizhe, touziguwen);
		printScore_1("与顾问pk的分数结果：", jigoutouzizhe->score, x, y[1], w, h);
		paly(jigoutouzizhe, WaiZi);
		hireplayer(jigoutouzizhe, WaiZi);
		printScore_1("与外资pk的分数结果：", jigoutouzizhe->score, x, y[2], w, h);
		paly(jigoutouzizhe, NeiBu);
		hireplayer(jigoutouzizhe, NeiBu);
		printScore_1("与内部pk的分数结果：", jigoutouzizhe->score, x, y[3], w, h);
	}
			  break;
	case sanhu: {paly(sanhutouzizhe, jigoutouzizhe);
		hireplayer(sanhutouzizhe, jigoutouzizhe);
		printScore_1("与机构pk的分数结果：", sanhutouzizhe->score, x, y[0], w, h);
		paly(sanhutouzizhe, touziguwen);
		hireplayer(sanhutouzizhe, touziguwen);
		printScore_1("与顾问pk的分数结果：", sanhutouzizhe->score, x, y[1], w, h);
		paly(sanhutouzizhe, WaiZi);
		hireplayer(sanhutouzizhe, WaiZi);
		printScore_1("与外资pk的分数结果：", sanhutouzizhe->score, x, y[2], w, h);
		paly(sanhutouzizhe, NeiBu);
		hireplayer(sanhutouzizhe, NeiBu);
		printScore_1("与内部pk的分数结果：", sanhutouzizhe->score, x, y[3], w, h);
	}
			  break;
	case guwen: {paly(touziguwen, jigoutouzizhe);
		hireplayer(touziguwen, jigoutouzizhe);
		printScore_1("与机构pk的分数结果：", touziguwen->score, x, y[0], w, h);
		paly(touziguwen, sanhutouzizhe);
		hireplayer(touziguwen, sanhutouzizhe);
		printScore_1("与散户pk的分数结果：", touziguwen->score, x, y[1], w, h);
		paly(touziguwen, WaiZi);
		hireplayer(touziguwen, WaiZi);
		printScore_1("与外资pk的分数结果：", touziguwen->score, x, y[2], w, h);
		paly(touziguwen, NeiBu);
		hireplayer(touziguwen, NeiBu);
		printScore_1("与内部pk的分数结果：", touziguwen->score, x, y[3], w, h);
	}
			  break;
	case waizi: {paly(WaiZi, jigoutouzizhe);
		hireplayer(WaiZi, jigoutouzizhe);
		printScore_1("与机构pk的分数结果：", WaiZi->score, x, y[0], w, h);
		paly(WaiZi, sanhutouzizhe);
		hireplayer(WaiZi, sanhutouzizhe);
		printScore_1("与散户pk的分数结果：", WaiZi->score, x, y[1], w, h);
		paly(WaiZi, touziguwen);
		hireplayer(WaiZi, touziguwen);
		printScore_1("与外资pk的分数结果：", WaiZi->score, x, y[2], w, h);
		paly(WaiZi, NeiBu);
		hireplayer(WaiZi, NeiBu);
		printScore_1("与内部pk的分数结果：", WaiZi->score, x, y[3], w, h);
	}
			  break;
	case neibu: {paly(NeiBu, jigoutouzizhe);
		hireplayer(NeiBu, jigoutouzizhe);
		printScore_1("与机构pk的分数结果：", NeiBu->score, x, y[0], w, h);
		paly(NeiBu, sanhutouzizhe);
		hireplayer(NeiBu, sanhutouzizhe);
		printScore_1("与散户pk的分数结果：", NeiBu->score, x, y[1], w, h);
		paly(NeiBu, touziguwen);
		hireplayer(NeiBu, touziguwen);
		printScore_1("与顾问pk的分数结果：", NeiBu->score, x, y[2], w, h);
		paly(NeiBu, WaiZi);
		hireplayer(NeiBu, WaiZi);
		printScore_1("与内部pk的分数结果：", NeiBu->score, x, y[3], w, h);
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
				MessageBox(GetHWnd(), _T("他们五位按顺序分别是投资顾问者、机构投资者、\n内部投资者、外资投资者、散户投资者"), _T("还记得他们吗？"), MB_OK);
				InputBox(yt, 100, "请输入投资顾问者的数量");
				InputBox(fdj, 100, "请输入机构投资者的数量");
				InputBox(fems, 100, "请输入内部投资者的数量");
				InputBox(hb, 100, "请输入外资投资者的数量");
				InputBox(xh, 100, "请输入散户投资者的数量");
				touziguwen_num = stod(yt);
				jigoutouzizhe_num = stod(fdj);
				NeiBu_num = stod(fems);
				WaiZi_num = stod(hb);
				sanhutouzizhe_num = stod(xh);

				button(688, 700, 150, 50, "Continue");



				//判断人数输入是否有误
				if (NeiBu_num < 0 || sanhutouzizhe_num < 0 || touziguwen_num < 0 || WaiZi_num < 0 || jigoutouzizhe_num < 0)
				{
					MessageBox(GetHWnd(), _T("输入人数错误，游戏退出"), _T("报错"), MB_OK);
					page = 4;
					mode = 0;
					exit(-1);
				}
				if (NeiBu_num == 0 && sanhutouzizhe_num == 0 && touziguwen_num == 0 && WaiZi_num == 0 && jigoutouzizhe_num == 0)
				{
					MessageBox(GetHWnd(), _T("嗯，你设置的模式真刁钻\n居然让所有人都输光光了诶"), _T("游戏结束"), MB_OK);
					page = 4;
					mode = 0;
					exit(-1);
				}

				//开始比赛

				char ip_1[50], nl_1[50];
				InputBox(ip_1, 50, "请输入进行比赛的次数，\n每一次比赛将最小分数者淘汰，增加一个最大分数者\n");
				InputBox(nl_1, 50, "请输入轮次\n即每两位投资者pk几次");
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
				printNum(touziguwen_num, jigoutouzizhe_num, NeiBu_num, WaiZi_num, sanhutouzizhe_num);//printNum还没有实现
				//判断最大最小并删小补大
				double max, min;
				max = -1000.0;
				min = 214748364.7;

				//判断最小

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

				//判断最大 

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



				//找最大最小
				//找最小

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


				//找最大

				if ((jigoutouzizhe->score == max) && (jigoutouzizhe_num != 0))
				{
					jigoutouzizhe_num += 1;
					MessageBox(GetHWnd(), _T("机构者是本轮最大赢家！"), _T("本次游戏结果"), MB_OK);
				}
				if ((sanhutouzizhe->score == max) && (sanhutouzizhe_num != 0))
				{
					sanhutouzizhe_num += 1;
					MessageBox(GetHWnd(), _T("散户投资者是本轮最大赢家！"), _T("本次游戏结果"), MB_OK);
				}
				if ((touziguwen->score == max) && (touziguwen_num != 0))
				{
					touziguwen_num += 1;
					MessageBox(GetHWnd(), _T("投资顾问者是本轮最大赢家！"), _T("本次游戏结果"), MB_OK);
				}
				if ((WaiZi->score == max) && (WaiZi_num != 0))
				{
					WaiZi_num += 1;
					MessageBox(GetHWnd(), _T("外资投资者是本轮最大赢家！"), _T("本次游戏结果"), MB_OK);
				}
				if ((NeiBu->score == max) && (NeiBu_num != 0))
				{
					NeiBu_num += 1;
					MessageBox(GetHWnd(), _T("内部投资者是本轮最大赢家！"), _T("本次游戏结果"), MB_OK);
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
		MessageBox(GetHWnd(), _T("恭喜你！赢得了博弈！"), _T("本轮游戏结束"), MB_OK);
	}
	else if (p1->score > p2->score) {
		putimage(800, 180, res.img_else + 8);
		putimage(780, 200, res.img_else + 0);
		MessageBox(GetHWnd(), _T("嘿嘿，你输啦~"), _T("本轮游戏结束"), MB_OK);
	}
}

void pk_inform(Player* p1, Player* p2) {
	if (p1->choice == 1 && p2->choice == 1) {
		MessageBox(GetHWnd(), _T("对方选择了 【合作】\n你们都+2"), _T("本次游戏结果"), MB_OK);
	}
	else if (p1->choice == 1 && p2->choice == 0) {
		MessageBox(GetHWnd(), _T("对方选择了 【合作】\n你+3\n对方-1"), _T("本次游戏结果"), MB_OK);
	}
	else if (p1->choice == 0 && p2->choice == 1) {
		MessageBox(GetHWnd(), _T("对方选择了 【欺骗】\n你-1\n对方+3"), _T("本次游戏结果"), MB_OK);
	}
	else if (p1->choice == 0 && p2->choice == 0) {
		MessageBox(GetHWnd(), _T("对方选择了 【欺骗】\n你们都+0"), _T("本次游戏结果"), MB_OK);
	}
}

void rule() {
	static int i;
	if (i == 0) {
		MessageBox(GetHWnd(), _T("若双方均选择欺骗，则双方得分均为0；\n若双方均选择合作，则双方得分均 + 2\n若玩家选择欺骗，对手选择合作，则玩家分数 + 3，对手分数 - 1\n若玩家选择合作，对手选择欺骗，则玩家分数 - 1, 对手分数 + 3 "), _T("游戏规则"), MB_OK);
		i = 1;
	}
}


/*开发日志：
1.设置一个交代人物选择的函数 finish
2.将人物倒下和分数保留在屏幕上的bug修改完成 finish
  就是立马有下一个putimage 立刻被覆盖了 以及介绍画面完毕之后的返回路径不太对
3. 设置第二个部分 pk完一次交代双方选择和分数 需要有一个按钮/单击任意位置继续动画 就像ppt finish
4.将第三个部分的第一张和按钮做好*/

