#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "head.h"


class Resource {
public:
    IMAGE img_start[5];
    IMAGE img_else[15];
    IMAGE img_bk[7];
    IMAGE img_intro[5];

    void loadAll(); 
    void BGM();
    //void playIntroVideo(HWND hwnd);
};
