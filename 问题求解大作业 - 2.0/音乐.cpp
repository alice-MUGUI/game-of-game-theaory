#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
void BGM() {
	//
	mciSendString("open 1.mp3 alias BGM",0,0,0);
	mciSendString("play BGM repeat", 0, 0, 0);
	if (0) {
		mciSendString("close BGM",0, 0, 0);
	}

}