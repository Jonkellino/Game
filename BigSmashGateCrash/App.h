#ifndef _APP_H_
#define _APP_H_

#include "Grid.h"
#include "Enemies.h"
#include "TileType.h"
#include "Sprite.h"
#include "LevelData.h"
#include "Buildings.h"
#include "PlayerData.h"
#include "Text.h"

enum class GameState 
{
	WAVE,
	BUILDING,
	MAIN_MENU
};

class App
{
public:
	App(void);
	~App(void);

	const bool Logic();
private:

	void Init();

	void ChooseTile(Vector2i aCurrentTile);

	void LevelUp();
	volatile bool myShouldQuit;

	void UpdateMoneyText();

	void UpdateHealthText();

	Grid<TileType> myGrid;
	Vector2i myTileSize;
	int myPreviousMoney;

	Sprite myPixelSprite;
	Sprite myTileSprite;
	Sprite myGoalSprite;
	
	Enemies myEnemies;
	PlayerData myPlayer;
	BuildingPlacer myBuildingPlacer;
	Buildings myBuildings;

	Text myMoneyText;
	Text myHealthText;
	Text myBuildPhaseText;
	Text myWavePhaseText;

	Text myCreditsText;
	Text myMainMenuText;


	LevelData myLevel;
	GameState myGameState;

	
	char* myMoneyString; 
	char* myHealthString;
	const uint16_t myMoneyStringBufferSize;

	Vector2i mySpawnWaveButtonPosition;
	Vector2i myMousePosition;
	uint32_t myCurrentMouseState;
	uint32_t myPreviousMouseState;

	int myPreviousHP;

	Sprite mySpawnWaveButton;
	
};

#endif