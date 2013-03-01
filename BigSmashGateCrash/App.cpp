#include "App.h"
#include "SDL\SDL_keyboard.h"
#include "SDL\SDL_mouse.h"
#include "SDL\SDL_timer.h"
#include <cassert>






App::App(void) : myMoneyStringBufferSize(30) {
	myMoneyString = nullptr;
	myHealthString = nullptr;
	Init();
}


App::~App(void) {
	delete[] myMoneyString;
	delete[] myHealthString;
}

const bool App::Logic() { 

	myCurrentMouseState = SDL_GetMouseState(&myMousePosition.x, &myMousePosition.y);

	Uint8 *state = SDL_GetKeyboardState(NULL);
	if(state[SDL_Scancode::SDL_SCANCODE_ESCAPE]) {
		myShouldQuit = true;
	}

	if(myGameState == GameState::MAIN_MENU) {
		myMainMenuText.Render();
		myCreditsText.Render();
		if(state[SDL_SCANCODE_SPACE]) {
			myGameState = GameState::BUILDING;
		}
		else {
			return myShouldQuit;
		}
	}

	static int prevMSSinceInit = 0;
	int currentTicks = SDL_GetTicks();
	const float delta = static_cast<float>(currentTicks - prevMSSinceInit) * 0.001f;
	
	myMoneyText.Render();
	myHealthText.Render();

	myGoalSprite.Data().pos = static_cast<Vector2i>(myGrid.Get(myGrid.Size()-1).GetPosition());
	myGoalSprite.Data().scale = Vector2f(0.85f, 0.85f);
	myGoalSprite.Render();
	
	

	if(myGameState == GameState::BUILDING) { 
		myBuildingPlacer.Logic(delta);
		if((myCurrentMouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) && ! (myPreviousMouseState & SDL_BUTTON(SDL_BUTTON_LEFT))) {
			if(myMousePosition.x > mySpawnWaveButtonPosition.x && myMousePosition.y > mySpawnWaveButtonPosition.y &&
				myMousePosition.x < mySpawnWaveButtonPosition.x + mySpawnWaveButton.Data().size.x && myMousePosition.y < mySpawnWaveButtonPosition.y + mySpawnWaveButton.Data().size.y) {
					myGameState = GameState::WAVE;
					LevelUp();
					myEnemies.SpawnWave(myLevel);
			}
		}
		mySpawnWaveButton.Data().pos = mySpawnWaveButtonPosition;
		mySpawnWaveButton.Render();

		myBuildPhaseText.Data().pos = Vector2i(1350, 450);
		myBuildPhaseText.Render();
		myEnemies.RenderPath();
	}
	myBuildings.Logic(delta);
	if(myGameState == GameState::WAVE) {
		if(myEnemies.Logic(delta) == false) {
			myGameState = GameState::BUILDING;
		}
		myWavePhaseText.Data().pos = Vector2i(1350, 450);
		myWavePhaseText.Render();
	}
	
	const Vector2i size = myGrid.Size2D();
	for(auto y = 0; y < size.y; ++y) {
		for(auto x = 0; x < size.x; ++x) { 
			TileType& tile = myGrid.Get(x,y);
			ChooseTile(Vector2i(x,y)); 
			myTileSprite.Data().pos = Vector2i(static_cast<int>(x * myTileSize.x), static_cast<int>(y * myTileSize.y));
			myTileSprite.Render(); 
		}
	}


	if(myPreviousMoney != myPlayer.money) {
		UpdateMoneyText();
	}
	if(myPreviousHP != myPlayer.health) {
		UpdateHealthText();
	}

	myPreviousMoney = myPlayer.money;
	myPreviousHP = myPlayer.health;

	prevMSSinceInit = currentTicks;
	myPreviousMouseState = myCurrentMouseState;


	if(myPlayer.health <= 0) {
		myGameState = GameState::MAIN_MENU;
		Init();
	}


	return myShouldQuit;
}

void App::Init() {
	myShouldQuit = false;

	myTileSize.x = 64;
	myTileSize.y = 64;
	Vector2i numberOfTiles(1024/myTileSize.x,1024/myTileSize.y);

	myGrid.Init(numberOfTiles, myTileSize);

	int tileSize = numberOfTiles.x * numberOfTiles.y;

	for(int y = 0; y < numberOfTiles.y; ++y) {
		for(int x = 0; x < numberOfTiles.x; ++x) {
			myGrid.Get(x,y).myPosition = Vector2f(static_cast<float>(x) * myTileSize.x + myTileSize.x*0.5f , static_cast<float>(y) * myTileSize.y + myTileSize.y*0.5f);
			myGrid.Get(x,y).blocked = false;
		}
	}

	myMainMenuText.Load("A.D. 2101 spacebar was beginning", "mainmenutext");
	myMainMenuText.Data().pos = Vector2i(1680 / 2, 1024 / 2);

	myCreditsText.Load("All art credits goes to opengameart.org. Made by @jonkellino. (www.Jonkel.com)", "creditstext");
	myCreditsText.Data().pos = Vector2i(1680 / 2, 1024 / 2 + 25);
	myBuildPhaseText.Load("Build phase! Delete: Destroy building. Full refunds!", "BuildPhaseText");
	myWavePhaseText.Load("Enemies incoming!", "WavePhaseText");

	myPixelSprite.Load("pixel.png");
	myPixelSprite.Data().color.r = 255;
	myPixelSprite.Data().color.g = 0;
	myPixelSprite.Data().color.b = 0;
	myPixelSprite.Data().color.a = 255;
	myPixelSprite.Data().size = Vector2i(10,10);

	myTileSprite.Load("cobbleset-64_0.png");
	myTileSprite.Data().size = myTileSize;
	myTileSprite.Data().hotspot = Vector2f(0,0); 
	myEnemies.Init(&myGrid, &myPlayer);
	myBuildings.Init(&myEnemies);
	myBuildingPlacer.Init(&myGrid, &myEnemies, &myBuildings, &myPlayer);


	myPlayer.money = 5;
	myPlayer.health = 10; 

	myMoneyString = new char[myMoneyStringBufferSize];
	myHealthString = new char[myMoneyStringBufferSize];
	UpdateMoneyText();
	UpdateHealthText();
	myMoneyText.Data().pos = Vector2i(1200, 500);
	myMoneyText.Data().color.g = 0;
	myHealthText.Data().pos = Vector2i(1200, 530);
	myHealthText.Data().color.r = 0;
	myHealthText.Data().color.b = 0;
	myPreviousMoney = myPlayer.money;

	myPreviousHP = -1;


	mySpawnWaveButton.Load("spawnwavebutton.png");
	mySpawnWaveButton.Data().hotspot = Vector2f(0.f,0.f);

	myGameState = GameState::MAIN_MENU;
	myPreviousMouseState = 0;
	myCurrentMouseState = 0;

	mySpawnWaveButtonPosition = Vector2i(1280, 700);

	myLevel.enemyMaxHealth = 5.f;
	myLevel.numberOfEnemiesToSpawn = 5;

	myGoalSprite.Load("heartshield.png");
}

enum dirs {
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3,
	DIR_SIZE
};
void App::ChooseTile(Vector2i aCurrentTile) {
	TileType& tile = myGrid.Get(aCurrentTile);
	bool adjacentBlocked[4]; 
	Vector2i directions[4] = {Vector2i(-1,0), Vector2i(1,0), Vector2i(0,-1), Vector2i(0,1)};


	for(int i = 0; i < DIR_SIZE; ++i) {
		adjacentBlocked[i] = true;
		if(myGrid.Inside(aCurrentTile + directions[i])) {
			if(myGrid.Get(aCurrentTile + directions[i]).IsTraverseable()) {
				adjacentBlocked[i] = false;
			}
		}	
	}


	// OH GOD WHY
	bool foundTileChange = false;
	if(tile.blocked){
		if(adjacentBlocked[LEFT] && 
			adjacentBlocked[RIGHT] && 
			adjacentBlocked[UP] && 
			adjacentBlocked[DOWN]) {

				myTileSprite.Data().topLeft = Vector2i(myTileSize.x * (aCurrentTile.x % 3), myTileSize.y * (aCurrentTile.y % 3));
		}
		else if(adjacentBlocked[LEFT] && 
			adjacentBlocked[RIGHT] && 
			adjacentBlocked[UP]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*1, myTileSize.y*5); 
				return;
		}
		else if(adjacentBlocked[LEFT] && 
			adjacentBlocked[RIGHT] && 
			adjacentBlocked[DOWN]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*1, myTileSize.y*3); 
				return;
		}
		else if(adjacentBlocked[UP] && 
			adjacentBlocked[RIGHT] && 
			adjacentBlocked[DOWN]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*0, myTileSize.y*4); 
				return;
		}
		else if(adjacentBlocked[UP] && 
			adjacentBlocked[LEFT] && 
			adjacentBlocked[DOWN]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*2, myTileSize.y*4); 
				return;
		}
		else if(adjacentBlocked[UP] &&
			adjacentBlocked[LEFT]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*2, myTileSize.y*5); 
		}
		else if(adjacentBlocked[UP] &&
			adjacentBlocked[RIGHT]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*0, myTileSize.y*5); 
		}
		else if(adjacentBlocked[DOWN] &&
			adjacentBlocked[RIGHT]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*0, myTileSize.y*3); 
		}
		else if(adjacentBlocked[DOWN] &&
			adjacentBlocked[LEFT]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*2, myTileSize.y*3); 
		}
		else if(adjacentBlocked[LEFT] &&
			adjacentBlocked[RIGHT]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*5, myTileSize.y*2); 
		}
		else if(adjacentBlocked[UP] &&
			adjacentBlocked[DOWN]) {
				myTileSprite.Data().topLeft = Vector2i(myTileSize.x*6, myTileSize.y*2); 
		}
		else if(adjacentBlocked[DOWN]) {
			myTileSprite.Data().topLeft = Vector2i(myTileSize.x*3, myTileSize.y*0);
		}
		else if(adjacentBlocked[UP]) {
			myTileSprite.Data().topLeft = Vector2i(myTileSize.x*3, myTileSize.y*1);	 
		}
		else if(adjacentBlocked[LEFT]) {
			myTileSprite.Data().topLeft = Vector2i(myTileSize.x*5, myTileSize.y*1);	 
		}
		else if(adjacentBlocked[RIGHT]) {
			myTileSprite.Data().topLeft = Vector2i(myTileSize.x*4, myTileSize.y*1);	 
		}
		else {
			myTileSprite.Data().topLeft = Vector2i(myTileSize.x*5, myTileSize.y*0);	 
		}
	}
	else
	{
		myTileSprite.Data().topLeft = Vector2i(myTileSize.x*6, myTileSize.y);
	}


}

void App::UpdateMoneyText() {
	_itoa(myPlayer.money, myMoneyString, 10); //TODO: warning. Fix own converting sys. 
	strcat_s(myMoneyString, myMoneyStringBufferSize, "$");
	Vector2i prevPos = myMoneyText.Data().pos;
	myMoneyText.Load(myMoneyString, "MoneyText");
	myMoneyText.Data().pos = prevPos;
}

void App::UpdateHealthText() {
	_itoa(myPlayer.health, myHealthString, 10);
	strcat_s(myHealthString, myMoneyStringBufferSize, " HP");
	Vector2i prevPos = myHealthText.Data().pos;
	myHealthText.Load(myHealthString, "HealthText");
	myHealthText.Data().pos = prevPos;
}

void App::LevelUp() {
	myLevel.enemyMaxHealth += static_cast<float>(myLevel.numberOfEnemiesToSpawn)*1.25f;
	++myLevel.numberOfEnemiesToSpawn;
}