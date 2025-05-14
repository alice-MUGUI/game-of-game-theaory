#include "UIHelper.h"
void drawButton(int x, int y, int w, int h, const char* text, COLORREF color)
{
	setbkmode(TRANSPARENT);
	setfillcolor(color);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	char text_[50] = { 0 };
	strcpy_s(text_, text);
	settextstyle(40, 0, "黑体");
	int tx = x + (w - textwidth(text_)) / 2;
	int ty = y + (h - textheight(text_)) / 2;
	outtextxy(tx, ty, text_);
}

void printScore(double score, int x, int y, int w, int h, COLORREF color)
{
	setbkmode(TRANSPARENT);
	setfillcolor(color);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(40, 0, "黑体");
	char text_[] = { "分数: " };
	char text_1[20];
	sprintf_s(text_1, "%.1f", score);
	int tx = x;// +(w - textwidth(text_) - textwidth(text_1)) / 2;
	int ty = y + (h - textheight(text_)) / 2;
	outtextxy(tx, ty, text_);
	outtextxy(tx + textwidth(text_), ty, text_1);
}

void printScore_1(const char* text, double score, int x, int y, int w, int h, COLORREF color) {
	setbkmode(TRANSPARENT);
	setfillcolor(color);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(40, 0, "黑体");
	char text_[50] = { 0 };
	strcpy_s(text_, text);
	char text_1[20];
	sprintf_s(text_1, "%.1f", score); // 只保留一位小数
	int tx = x;// +(w - textwidth(text_) - textwidth(text_1)) / 2;
	int ty = y + (h - textheight(text_)) / 2;
	outtextxy(tx, ty, text_);
	outtextxy(tx + textwidth(text_), ty, text_1);
}
void printNum(int num_1, int num_2, int num_3, int num_4, int num_5, int x, int y, int w, int h, COLORREF color)
{
	setbkmode(TRANSPARENT);
	setfillcolor(color);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(40, 0, "黑体");
	char text_[5][50] = { " 顾问:" ,"  机构:","   内部:","   外资:","   散户:" };
	char text_1[5][50];
	sprintf_s(text_1[0], "%d", num_1);
	sprintf_s(text_1[1], "%d", num_2);
	sprintf_s(text_1[2], "%d", num_3);
	sprintf_s(text_1[3], "%d", num_4);
	sprintf_s(text_1[4], "%d", num_5);
	int tx = x;
	int ty = y + (h - textheight(text_[0])) / 2;
	for (int i = 0; i < 5; i++) {
		outtextxy(tx + i * (textwidth(text_[1]) + textwidth(text_1[1])), ty, text_[i]);
		if (i == 0)outtextxy(tx + 120, ty, text_1[0]);
		else outtextxy(tx + i * (textwidth(text_[1]) + textwidth(text_1[1])) + 170, ty, text_1[i]);
	}
}
bool isInRect(ExMessage* msg, int x, int y, int w, int h)//鼠标是否在某个矩形内
{
	if (msg->x > x && msg->x<x + w && msg->y>y && msg->y < y + h)
	{
		return true;
	}
	return false;
}