#define _CRT_SECURE_NO_WARNINGS
#include "head.h"



void startupScene(ExMessage*msg) {//鼠标左键单击后切换画面   
	if (msg->message == WM_LBUTTONDOWN) {
		putimage(0, 0, res.img_start +  page);
		++ page;
	}
}
void home(ExMessage*msg) {
	t= 0;
	page = 4;
	mode = 0;
	if (msg->message == WM_LBUTTONDOWN) {
		putimage(0, 0, res.img_start +  page);
		button(200, 90, 300, 75, "我来博弈");
		button(200, 220, 300, 75, "两两博弈");
		button(200, 350, 300, 75, "市场博弈");
		if (isInRec(msg, 200, 90, 300, 75)) {

			 page++;
			 mode = 1;
		}
		else if (isInRec(msg, 200, 220, 300, 75)) {
			page++;
			mode = 2;
		}
		else if (isInRec(msg, 200, 350, 300, 75)) {
			page++;
			mode = 3;
		}
	}
}
void  mode_1_start(ExMessage* msg) {
	BeginBatchDraw();
	putimage(0, 0, res.img_bk + mode);
	button(341, 520, 200, 50, "1号投资者");
	button(797, 520, 200, 50, "2号投资者");
	button(114, 680, 200, 50, "3号投资者");
	button(569, 680, 200, 50, "4号投资者");
	button(1024, 680, 200, 50, "5号投资者");
	button(0, 0, 150, 50, "home");
	EndBatchDraw();
	if (msg->message == WM_LBUTTONDOWN) {
		if (isInRec(msg, 341, 520, 200, 50)) { who = guwen; }
		else if (isInRec(msg, 797, 520, 200, 50)) { who = jigou; }
		else if (isInRec(msg, 114, 680, 200, 50)) { who = neibu; }
		else if (isInRec(msg, 569, 680, 200, 50)) { who = waizi; }
		else if (isInRec(msg, 1024, 680, 200, 50)) { who = sanhu; }
		if (who >= 1 && who <= 5) {
			 page=6;
		}
		putimage(0, 0, res.img_bk + 0);
		//button(638, 340, 50, 50, "PK");
		putimage(0, 0, res.img_bk + 4);
		putimage(280, 180, res.img_else + who);
		putimage(800, 180, res.img_else + 6);
		button(850, 720, 100, 50, "合作");
		button(1000, 720, 100, 50, "欺骗");
	}
}
void mode_2_start(ExMessage* msg) {
	BeginBatchDraw();
	putimage(0, 0, res.img_bk + mode);
	button(341, 520, 200, 50, "顾问投资者");
	button(797, 520, 200, 50, "机构投资者");
	button(114, 680, 200, 50, "内部投资者");
	button(569, 680, 200, 50, "外资投资者");
	button(1024, 680, 200, 50, "散户投资者");
	button(0, 0, 150, 50, "home");
	EndBatchDraw();
	if (msg->message == WM_LBUTTONDOWN) {
		if (isInRec(msg, 341, 520, 200, 50)) { who = guwen; }
		else if (isInRec(msg, 797, 520, 200, 50)) { who = jigou; }
		else if (isInRec(msg, 114, 680, 200, 50)) { who = neibu; }
		else if (isInRec(msg, 569, 680, 200, 50)) { who = waizi; }
		else if (isInRec(msg, 1024, 680, 200, 50)) { who = sanhu; }
		if (who >= 1 && who <= 5) {
			page = 6;
		}
		putimage(0, 0, res.img_bk + 0);
		putimage(0, 0, res.img_bk + 5);
		putimage(150, 180, res.img_else + who);
		//button(600, 720, 150, 50, "查看pk结果");
	}
}
void mode_3_start(ExMessage* msg) {
	putimage(0, 0, res.img_bk + mode);
	button(0, 0, 150, 50, "home");
	button(688, 700, 150, 50, "Begin");
	if (msg->message == WM_LBUTTONDOWN) {
		if (isInRec(msg, 688, 700, 150, 50)) {
			page++; putimage(0, 0, res.img_bk + 6);
		}
	}
}


void back_home(ExMessage* msg) {
	if (msg->message == WM_LBUTTONDOWN) {
		if (isInRec(msg, 0, 0, 200, 70)) {
			button(0, 0, 200, 70, "home");
			page = 4;
			mode = 0;
			who = kong;
			t = 0;
			home(msg);
		}
	}
}
void back_start(ExMessage* msg) {
	if (msg->message == WM_LBUTTONDOWN && isInRec(msg, 0, 0, 200, 70)) {
		page = 5;
		who = kong;
		t = 0;
		/*
		if (mode == 1)mode_1_start(msg);
		else if (mode == 2) mode_2_start(msg);
		else if (mode == 3)mode_3_start(msg);*/
	}
}

