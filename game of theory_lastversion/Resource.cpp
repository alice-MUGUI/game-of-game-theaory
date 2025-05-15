#include "Resource.h"
#include <mfapi.h>
#include <mfplay.h>
#include <mfobjects.h>
#include <mfreadwrite.h>
#include <mfidl.h>
#include <shlwapi.h>

#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "mf.lib")
#pragma comment(lib, "mfplay.lib")
#pragma comment(lib, "mfreadwrite.lib")
#pragma comment(lib, "ole32.lib")

void Resource:: loadAll() {
	for (int i = 1; i < 5; i++) {
		char path[50] = { 0 };
		sprintf_s(path, "images/startup/%d.png", i + 1);
		loadimage(img_start + i, path, getwidth(), getheight());
	}
	int w = 300, h = 410;
	loadimage(img_start + 0, "images/startup/1.jpg");
	loadimage(img_else + 0, "images/else/zu.jpg", 420, 270);
	loadimage(img_else + 1, "images/else/guwen.jpg", w, h);
	loadimage(img_else + 2, "images/else/jigou.jpg", w, h);
	loadimage(img_else + 3, "images/else/neibu.jpg", w, h);
	loadimage(img_else + 4, "images/else/waizi.jpg", w, h);
	loadimage(img_else + 5, "images/else/sanhu.jpg", w, h);
	loadimage(img_else + 6, "images/else/me.jpg", w, h);
	loadimage(img_else + 7, "images/else/pk.png", 100, 100);
	loadimage(img_else + 8, "images/else/kong.jpg", w, h); 
	loadimage(img_bk + 0, "images/tiaozhuanye/kong.jpg", getwidth(), getheight());
	loadimage(img_bk + 1, "images/tiaozhuanye/wolaiboyi.png", getwidth(), getheight());
	loadimage(img_bk + 2, "images/tiaozhuanye/liangliangboyi.png", getwidth(), getheight());
	loadimage(img_bk + 3, "images/tiaozhuanye/shichangboyi.png", getwidth(), getheight());
	loadimage(img_bk + 4, "images/pk/1.jpg", getwidth(), getheight());
	loadimage(img_bk + 5, "images/pk/2.jpg", getwidth(), getheight());
	loadimage(img_bk + 6, "images/pk/3.jpg", getwidth(), getheight());

	for (int i = 0; i < 5; i++) {
		char path[50] = { 0 };
		sprintf_s(path, "images/wanjiajieshao/%d.png", i + 1);
		loadimage(img_intro + i, path, getwidth(), getheight());
	}
}

void Resource::BGM() {
	//
	mciSendString("open 1.mp3 alias BGM", 0, 0, 0);
	mciSendString("play BGM repeat", 0, 0, 0);
	if (0) {
		mciSendString("close BGM", 0, 0, 0);
	}

}
static IMFPMediaPlayer* g_pPlayer = NULL;

void CALLBACK OnMediaEnded(void* pCallbackContext) {
	HWND hwnd = (HWND)pCallbackContext;
	PostMessage(hwnd, WM_USER + 1, 0, 0);
}
/*
void Resource::playIntroVideo(HWND hwnd) {
	MFStartup(MF_VERSION);

	MFP_CREATE_OPTIONS createOptions = { 0 };
	createOptions.dwCreationFlags = MFP_OPTION_NO_AUDIO;
	createOptions.hWnd = hwnd;

	HRESULT hr = MFPCreateMediaPlayer(
		NULL,
		FALSE,
		0,
		NULL,
		hwnd,
		&g_pPlayer
	);

	if (FAILED(hr)) {
		MessageBox(hwnd, "无法创建播放器", "错误", MB_OK);
		return;
	}

	g_pPlayer->SetEndOfPresentationEventCallback(OnMediaEnded, hwnd);
	g_pPlayer->CreateMediaItemFromURL(L"video.mp4", FALSE, 0, NULL); // 确保路径正确
	g_pPlayer->Play();
}*/