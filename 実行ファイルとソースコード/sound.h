
#pragma once

#include <windows.h>
#include "xaudio2.h"
#include "xaudio2fx.h"
#include "declaration.h"

bool InitSound(HWND hWnd);
void UninitSound(void);

int LoadSound(char* pFilename);
void PlaySound(int index, int loopCount);
void StopSound(int index);
void StopSoundAll(void);
void SetVolume(int index, float vol);

float GetFrequency(int index);					//現在の周波数(ピッチ)の割合
UINT64 GetSourceSample(int index);			//indexの現在のサンプル数
void SetFrequency(int index, float ratio);	//周波数(ピッチ)の設定(0.0f～2.0f)

void SetSampleNum(SOUND_BGM_NUM bgm_num, UINT32 num);