#pragma once
#include <graphics.h>
#include <string>

void drawButton(int x, int y, int w, int h, const char* text, COLORREF color = RED);
void printScore(double score, int x = 235, int y = 620, int w = 300, int h = 50, COLORREF color = RED);
void printScore_1(const char* text, double score, int x = 235, int y = 620, int w = 300, int h = 50, COLORREF color = RED);
void printNum(int num_1, int num_2, int num_3, int num_4, int num_5, int x = 260, int y = 100, int w = 850, int h = 50, COLORREF color = BLACK);
bool isInRect(ExMessage* msg, int x, int y, int w, int h);//鼠标是否在某个矩形内

/*
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
		else if (mode == 3)mode_3_start(msg);
	}
}
*/

