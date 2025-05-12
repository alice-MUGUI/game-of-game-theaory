#define _CRT_SECURE_NO_WARNINGS
#include "head.h"


//��ʼ����Դ
void res_init(struct Resource* res) {
	for (int i = 1; i < 5; i++) {
		char path[50] = { 0 };
		sprintf_s(path, "images/startup/%d.png", i + 1);
		loadimage(res->img_start + i, path, getwidth(), getheight());
	}
	int w = 300, h = 410;
	loadimage(res->img_start + 0, "images/startup/1.jpg");
	loadimage(res->img_else + 0, "images/else/zu.jpg", 420, 270);
	loadimage(res->img_else + 1, "images/else/guwen.jpg", w, h);
	loadimage(res->img_else + 2, "images/else/jigou.jpg", w, h);
	loadimage(res->img_else + 3, "images/else/neibu.jpg", w, h);
	loadimage(res->img_else + 4, "images/else/waizi.jpg", w, h);
	loadimage(res->img_else + 5, "images/else/sanhu.jpg", w, h);
	loadimage(res->img_else + 6, "images/else/me.jpg", w, h);
	loadimage(res->img_else + 7, "images/else/pk.png", 100, 100);
	loadimage(res->img_else + 8, "images/else/kong.jpg", w, h);
	loadimage(res->img_bk + 0, "images/tiaozhuanye/kong.jpg", getwidth(), getheight());
	loadimage(res->img_bk + 1, "images/tiaozhuanye/wolaiboyi.png", getwidth(), getheight());
	loadimage(res->img_bk + 2, "images/tiaozhuanye/liangliangboyi.png", getwidth(), getheight());
	loadimage(res->img_bk + 3, "images/tiaozhuanye/shichangboyi.png", getwidth(), getheight());
	loadimage(res->img_bk + 4, "images/pk/1.jpg", getwidth(), getheight());
	loadimage(res->img_bk + 5, "images/pk/2.jpg", getwidth(), getheight());
	loadimage(res->img_bk + 6, "images/pk/3.jpg", getwidth(), getheight());

	for (int i = 0; i < 5; i++) {
		char path[50] = { 0 };
		sprintf_s(path, "images/wanjiajieshao/%d.png", i + 1);
		loadimage(res->img_intro + i, path, getwidth(), getheight());
	}
}
void startupScene(ExMessage*msg) {//�������������л�����   
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
		button(200, 90, 300, 75, "��������");
		button(200, 220, 300, 75, "��������");
		button(200, 350, 300, 75, "�г�����");
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
	button(341, 520, 200, 50, "1��Ͷ����");
	button(797, 520, 200, 50, "2��Ͷ����");
	button(114, 680, 200, 50, "3��Ͷ����");
	button(569, 680, 200, 50, "4��Ͷ����");
	button(1024, 680, 200, 50, "5��Ͷ����");
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
		button(850, 720, 100, 50, "����");
		button(1000, 720, 100, 50, "��ƭ");
	}
}
void mode_2_start(ExMessage* msg) {
	BeginBatchDraw();
	putimage(0, 0, res.img_bk + mode);
	button(341, 520, 200, 50, "����Ͷ����");
	button(797, 520, 200, 50, "����Ͷ����");
	button(114, 680, 200, 50, "�ڲ�Ͷ����");
	button(569, 680, 200, 50, "����Ͷ����");
	button(1024, 680, 200, 50, "ɢ��Ͷ����");
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
		//button(600, 720, 150, 50, "�鿴pk���");
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

void button(int x, int y, int w, int h, const char* text, COLORREF color) {
	setbkmode(TRANSPARENT);
	setfillcolor(color);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	char text_[50] = { 0 };
	strcpy(text_, text);
	settextstyle(40, 0, "����");
	int tx = x + (w - textwidth(text_)) / 2;
	int ty = y + (h - textheight(text_)) / 2;
	outtextxy(tx, ty, text_);
}


void printScore(double score, int x, int y, int w, int h, COLORREF color) {
	setbkmode(TRANSPARENT);
	setfillcolor(color);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(40, 0, "����");
	char text_[] = { "����: " };
	char text_1[20] ;
	sprintf(text_1, "%f", score);
	int tx = x;// +(w - textwidth(text_) - textwidth(text_1)) / 2;
	int ty = y + (h - textheight(text_)) / 2;
	outtextxy(tx, ty, text_);    
	outtextxy(tx + textwidth(text_), ty, text_1);
}
void printScore_1(const char* text,double score, int x, int y, int w, int h, COLORREF color) {
	setbkmode(TRANSPARENT);
	setfillcolor(color);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(40, 0, "����");
	char text_[50] = { 0 };
	strcpy(text_, text);
	char text_1[20];
	sprintf(text_1, "%f", score);
	int tx = x;// +(w - textwidth(text_) - textwidth(text_1)) / 2;
	int ty = y + (h - textheight(text_)) / 2;
	outtextxy(tx, ty, text_);
	outtextxy(tx + textwidth(text_), ty, text_1);
}
void printNum(int num_1, int num_2, int num_3, int num_4, int num_5, int x, int y, int w, int h, COLORREF color) {
	setbkmode(TRANSPARENT);
	setfillcolor(color);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(40, 0, "����");
	char text_[5][50] = { " ����:" ,"  ����:","   �ڲ�:","   ����:","   ɢ��:"};
	char text_1[5][50];
	sprintf(text_1[0], "%d", num_1);
	sprintf(text_1[1], "%d", num_2);
	sprintf(text_1[2], "%d", num_3);
	sprintf(text_1[3], "%d", num_4);
	sprintf(text_1[4], "%d", num_5);
	int tx = x;
	int ty = y + (h - textheight(text_[0])) / 2;
	for (int i = 0; i < 5; i++) {
		outtextxy(tx + i * (textwidth(text_[1]) + textwidth(text_1[1])),ty,text_[i]);
		if (i == 0)outtextxy(tx+120,ty,text_1[0]);
		else outtextxy(tx + i * (textwidth(text_[1]) + textwidth(text_1[1]))+170, ty, text_1[i]);
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
	if (msg->message == WM_LBUTTONDOWN&& isInRec(msg, 0, 0, 200, 70)) {
			page = 5;
			who = kong;
			t = 0;
			/*
			if (mode == 1)mode_1_start(msg);
			else if (mode == 2) mode_2_start(msg);
			else if (mode == 3)mode_3_start(msg);*/
		}
	}

bool isInRec(ExMessage* msg, int x, int y, int w, int h)//����Ƿ���ĳ��������
{
	if (msg->x > x && msg->x<x + w && msg->y>y && msg->y < y + h)
	{
		return true;
	}
	return false;
}
