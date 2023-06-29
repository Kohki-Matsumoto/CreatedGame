#include "Scene.h"
#include"Title.h"
#include"Menu.h"
#include "Config.h"
#include"SubConfig.h"
#include"Result.h"
#include "Scene.h"
#include"Title.h"
#include"Menu.h"
#include "Config.h"
#include"SubConfig.h"
#include"Result.h"
#include "Game.h"
#include"declaration.h"
#include "fade.h"

static SCENE g_SceneIndex = SCENE_NONE;
static SCENE g_SceneNextIndex = g_SceneIndex;

bool asidaokfl = true;

void InitScene(SCENE index)
{
	g_SceneIndex = g_SceneNextIndex = index;
	switch (g_SceneIndex)
	{

	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		InitTitle();
		break;

	case SCENE_MENU:
		InitMenu();
		break;

	case SCENE_GAME:

		InitGame();
		break;

	case SCENE_CONFIG:
		InitConfig();
		break;

	case SCENE_SUBCONFIG:
		InitSubConfig();
		break;

	case SCENE_RESULT:
		InitResult();
		break;
	}
	
}


void UninitScene(void)
{
	switch (g_SceneIndex)
	{

	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		UninitTitle();
		break;

	case SCENE_MENU:
		UninitMenu();
		break;

	case SCENE_GAME:

		UnInitGame();
		break;

	case SCENE_CONFIG:
		UninitConfig();
		break;

	case SCENE_SUBCONFIG:
		UninitSubConfig();
		break;

	case SCENE_RESULT:
		UninitResult();
		break;
	}
	
}


void UpdateScene(void)
{
	switch(g_SceneIndex)
	{

	case SCENE_NONE:
		break;

	case SCENE_TITLE:
  		UpdateTitle();
		break;

	case SCENE_MENU:
		UpdateMenu();
		break;

	case SCENE_GAME:

		UpdateGame();
		break;

	case SCENE_CONFIG:
		UpdateConfig();
		break;

	case SCENE_SUBCONFIG:
		UpdateSubConfig();
		break;

	case SCENE_RESULT:
		UpdateResult();
		break;
	}
	UpdateFade();
}

void DrawScene(void)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		DrawTitle();
		break;

	case SCENE_MENU:
		DrawMenu();
		break;

	case SCENE_GAME:

		DrawGame();
		break;

	case SCENE_CONFIG:
		DrawConfig();
		break;

	case SCENE_SUBCONFIG:
		DrawSubConfig();
		break;

	case SCENE_RESULT:
		DrawResult();
		break;
	}
	DrawFade();
}

void SetScene(SCENE sceneindex)
{
	g_SceneNextIndex = sceneindex;
}

void CheckScene(void)
{
	//現在のシーンと遷移先シーンが違っていたら
	if (g_SceneIndex != g_SceneNextIndex)
	{
		//現在のシーンを終了させる
		UninitScene();

		//遷移先シーンの初期化処理を行う
		InitScene(g_SceneNextIndex);
	}
}

