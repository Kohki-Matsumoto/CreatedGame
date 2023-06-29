/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "FileRead.h"
#include "declaration.h"

#define SEARCH_LETTER 100

using namespace std;

const char* StageInfFileName = W1_S1_INF_001;

//=======================================================
struct Player
{
	int MaxField = 0;
	float Speed = 0.0f;
};

struct Field
{
	int FieldNom = 0;
	float FieldPosX = 0.0f;
	float FieldPosY = 0.0f;
	float FieldSizeX = 0.0f;
	float FieldSizeY = 0.0f;
	int TexNom = 0;
};
//=======================================================

void FileRead()
{
	FILE* fp;

	char lines[63 + 1] = { 0 };

	//=======================================================
	Player player;
	Field field;
	//=======================================================leName, "r");

	// ファイルが開けるかを確認する
	if (fp == NULL) {
		printf("Not open?\n");
	}

	while (fgets(lines, sizeof(lines), fp) != NULL)
	{
		if (lines[0] == 'm' && lines[1] == 'f')
		{
			for (int i = 3; i < SEARCH_LETTER; i++)
			{
				if (lines[i] == ',' || lines[i] == '\n')
				{
					char a[5];
					for (int k = 0; k < i - 3; k++)
						a[k] = lines[3 + k];
					player.MaxField = stoi(a);
					break;
				}
			}
		}
		if (lines[0] == 'p' && lines[1] == 's')
		{
			for (int i = 3; i < SEARCH_LETTER; i++)
			{
				if (lines[i] == ',' || lines[i] == '\n')
				{
					char a[11];
					for (int k = 0; k < i - 3; k++)
						a[k] = lines[3 + k];
					player.Speed = stof(a);
					break;
				}
			}
		}
		if (lines[0] == 'f' && lines[1] == 'p')
		{
			int count = 0;
			int	StartLetter = 0;

			for (int i = 3; i < SEARCH_LETTER; i++)
			{
				if (lines[i] == ',' && count == 0)
				{
					char a[10];
					for (int k = 0; k < i - 3; k++)
						a[k] = lines[3 + k];
					field.FieldNom = stoi(a);
					count++;
					StartLetter = i + 1;
					continue;
				}
				if (lines[i] == ',' && count == 1)
				{
					char a[10];
					for (int k = 0; k < i - StartLetter; k++)
						a[k] = lines[StartLetter + k];
					field.FieldPosX = stof(a);
					count++;
					StartLetter = i + 1;
					continue;
				}
				if (lines[i] == ',' && count == 2)
				{
					char a[10];
					for (int k = 0; k < i - StartLetter; k++)
						a[k] = lines[StartLetter + k];
					field.FieldPosY = stof(a);
					count++;
					StartLetter = i + 1;
					continue;
				}
				if (lines[i] == ',' && count == 3)
				{
					char a[10];
					for (int k = 0; k < i - StartLetter; k++)
						a[k] = lines[StartLetter + k];
					field.FieldSizeX = stof(a);
					count++;
					StartLetter = i + 1;
					continue;
				}
				if (lines[i] == ',' && count == 4)
				{
					char a[10];
					for (int k = 0; k < i - StartLetter; k++)
						a[k] = lines[StartLetter + k];
					field.FieldSizeY = stof(a);
					count++;
					StartLetter = i + 1;
					continue;
				}
				if (lines[i] == '\n' && count == 5)
				{
					char a[10];
					for (int k = 0; k < i - StartLetter; k++)
						a[k] = lines[StartLetter + k];
					field.TexNom = stoi(a);
					break;
				}
			}
		}
	}

	fclose(fp);

}

*/