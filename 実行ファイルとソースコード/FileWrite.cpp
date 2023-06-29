/*
#define _CRT_SECURE_NO_WARNINGS

#include "FileWrite.h"
#include "declaration.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


const char* StageInfFileName = W1_S1_INF_001;


void FileWrite()
{
    //==================================================
    float PlayerSpeed = 10.5f;

    Base_Field_Inf answer[30] = { 80.0300f, 33330.0f, 10110.0332f, 23330.0333f, 3 };
    answer[1] = { 8.0f, 33.0f, 10.2f, 2.3f, 3 };
    int NowMaxField = sizeof(answer) / sizeof(answer[0]);

    //==================================================

	FILE* fp;

	fp = fopen(StageInfFileName, "w");

    //---------------------------------------------------------
    // ファイル書き込み開始
    //---------------------------------------------------------

    // フィールドの最大数を書き込み
    fprintf(fp, "mf,%d\n", NowMaxField);

    // プレイヤーのスピード(ステージのスピードを書き込み)
    fprintf(fp, "ps,%f\n", PlayerSpeed);

    //フィールドの情報を書き込み
    for (int i = 0; i < NowMaxField; i++)
    {
        fprintf(fp, "fp,%d,%f,%f,%f,%f,%d\n", i, answer[i].Pos.x, answer[i].Pos.y, answer[i].Size.x, answer[i].Size.y, answer[i].TexNum);
    }

    //---------------------------------------------------------
    // ファイル書き込み終了
    //---------------------------------------------------------

    fclose(fp);
}

*/