#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
using namespace std;
int nl, em;//全局变量 已有外部声明
int jigoutouzizhe_num, sanhutouzizhe_num, touziguwen_num, WaiZi_num, NeiBu_num;//全局 已声明
Player* jigoutouzizhe;
Player* sanhutouzizhe;
Player* touziguwen;
Player* WaiZi;
Player* NeiBu;
Player* me;
int page ;
Resource res;
int mode;
int t;
Wanjia who;

int main()
{

	initgraph(1366, 780);
	BGM();
	jigoutouzizhe = new Player[10];
	sanhutouzizhe = new Player[10];
	touziguwen = new Player[10];
	WaiZi = new Player[10];
	NeiBu = new Player[10];
	me = new Player[10];
	page = 1;
	t = 0;
	mode = 0;

	res_init(&res);
	putimage(0, 0, res.img_start + 0);
	while (true) {
		ExMessage msg;
		while (peekmessage(&msg, EX_MOUSE))//检测有无鼠标信息
		{
			if (page < 4) {
				startupScene(&msg);
			}
			else if (page == 4) {
				home(&msg);
			}
			else if (page == 5) {
				back_home(&msg);
				if (mode == 1) {
					mode_1_start(&msg);
				}
				else if (mode == 2) { mode_2_start(&msg); }
				else if (mode == 3) { mode_3_start(&msg); }
			}
			else if (page >= 6) {
				button(0, 0, 200, 70, "back");
				back_start(&msg);
				if (mode == 1) {
					mode_1_pk(&msg);
				}
				if (mode == 2) {
					mode_2_pk(&msg);
				}
				if (mode == 3) {
					mode_3_pk(&msg);
				}
			}
		}
	}

	delete[]jigoutouzizhe;
	delete[]touziguwen;
	delete[]sanhutouzizhe;
	delete[]WaiZi;
	delete[]NeiBu;
	
}

