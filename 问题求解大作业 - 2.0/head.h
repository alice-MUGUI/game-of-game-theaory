#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include<vector>
#include<iostream>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include<easyx.h>
#include <conio.h>
#include<string>
using namespace std;

struct Player
{
	double score;
	int choice;
	int n;
	char name[100];
};
extern int nl, em;
extern int NeiBup, temp1, temp2;
extern int jigoutouzizhe_num, sanhutouzizhe_num, touziguwen_num, WaiZi_num, NeiBu_num;
extern Player* jigoutouzizhe, * sanhutouzizhe, * touziguwen, * WaiZi, * NeiBu,*me;
void isscore(Player* p1, Player* p2);//判断胜负的函数
void isscores(Player* p1, Player* p2);
void hireplayerh(Player* p1, Player* p2);
//初始化结构体
void Initsanhutouzizhe(Player* sanhutouzizhe);
void Initjigoutouzizhe(Player* jigoutouzizhe);
void Inittouziguwen(Player* jigoutouzizhe);
void InitWaiZi(Player* WaiZi);
void InitNeiBu(Player* NeiBu);
//游戏算法
void paly(Player* p1, Player* p2);
void palyy(Player* p1, Player* p2);
//打印页面
void menu(int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num);
//进行一次比赛
void Competition(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num);
//在比赛后恢复的函数
void hireplayer(Player* p1, Player* p2);
//完成复读机比赛的函数
Player* playjigoutouzizhe(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num);
//小红
Player* playsanhutouzizhe(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num);
//touziguwen
Player* playtouziguwen(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num);
//WaiZi
Player* playWaiZi(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num);
//NeiBu
Player* playNeiBu(Player* jigoutouzizhe, Player* sanhutouzizhe, Player* touziguwen, Player* WaiZi, Player* NeiBu, int jigoutouzizhe_num, int sanhutouzizhe_num, int touziguwen_num, int WaiZi_num, int NeiBu_num);

void BGM();
//BGM函数声明

enum Wanjia { kong, guwen, jigou, neibu, waizi, sanhu };
struct Resource {
	IMAGE img_start[5];//定义一个数组
	IMAGE img_else[15];//home菜单跳转到的页面
	IMAGE img_bk[7];//作为背景和清屏使用
	IMAGE img_intro[5];//五个投资者的介绍界面
};
bool isInRec(ExMessage*, int, int, int, int);
//鼠标位置判断
void rule();
void res_init(struct Resource*);
void startupScene(ExMessage*);
void home(ExMessage*);
void back_home(ExMessage*);
void back_start(ExMessage*);
void mode_1_start(ExMessage*);
void mode_1_pk(ExMessage*);
void mode_2_start(ExMessage*);
void mode_2_pk(ExMessage*);
void mode_3_start(ExMessage* );
void mode_3_pk(ExMessage*);
void pk_winner(Player* , Player* );
void pk_inform(Player* , Player* );
void button(int, int, int, int, const char*, COLORREF color=RED);
void printScore(double, int x = 235, int y = 620, int w = 300, int h = 50, COLORREF color = RED);
void printScore_1(const char*, double, int x = 235, int y = 620, int w = 300, int h = 50, COLORREF color = RED);
void printNum(int num_1, int num_2, int num_3, int num_4, int num_5, int x = 260, int y = 100, int w = 850, int h = 50, COLORREF color = BLACK);

/*struct Situation {
	int page;
	int mode;
	int t;
};*/
extern Resource res;
extern int mode;
extern Wanjia who;
extern int page;
extern int t;
//extern Situation situa;


