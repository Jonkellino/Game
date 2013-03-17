#include "App.h"
#include "SDL\SDL.h"
#include "Keyboard.h"
#include "Engine.h"

#include "Handgun.h"
#include "Fist.h"

App::App(void)
{
	myFPSTextBuffer = new char[16];
	myFPSTextBuffer[0] = '\0';
	myFPSText.Load(myFPSTextBuffer, "FPSText");
	myFPSText.Data().pos = Vector2i(0,0);
	myFPSText.Data().hotspot = Vector2f(0,0);
	myFPSText.Data().depth = -1000.f;

	myCamera.Init(static_cast<Vector2f>(Engine::GetInstance()->GetWindowSize())); 
	b2World* currentWorld = myPhysics.GetWorld();

	myEnemy.Init(currentWorld);
	myPlayer.Init(currentWorld);
	myMap.Init(currentWorld);

	for( unsigned int index = 0; index < 5; index++ )
	{
		Handgun* test = new Handgun();
		bool gotEquipped = myPlayer.GetInventory().AddItem( test );
		if( !gotEquipped )
		{
			delete test;
		}
	}

	Fist* test = new Fist();
	bool gotEquipped = myPlayer.GetInventory().AddItem( test );
	if( !gotEquipped )
	{
		delete test;
	}

	for( unsigned int index = 0; index < 5; index++ )
	{
		Handgun* test = new Handgun();
		bool gotEquipped = myPlayer.GetInventory().AddItem( test );
		if( !gotEquipped )
		{
			delete test;
		}
	}
}

App::~App(void)
{
	delete myFPSTextBuffer;
}

bool App::Logic( const float aDelta )
{
	KeyboardInput->Update();
	if(KeyboardInput->KeyDown(SDL_SCANCODE_ESCAPE))
	{
		return true;
	}
	RenderFPS( aDelta );

	static const float physicsFps = 30;
	static const float timeStep = 1 / physicsFps;
	static float physicsTimer = 0;
	physicsTimer += aDelta;
	while( physicsTimer >= timeStep )
	{
		physicsTimer -= timeStep;
		myPhysics.Step( timeStep );
		FixedUpdate( timeStep );
	}
	 
	Render(); 
	Update( aDelta ); 

	return false;
}

void App::RenderFPS(const float aDelta) 
{
	myFPSTextBuffer[0] = '\0';
	_itoa_s( static_cast<int>(1.f/aDelta), myFPSTextBuffer, 16, 10 );
	myFPSText.Load(myFPSTextBuffer, "FPSText");
	myFPSText.Render();
}

void App::Update( const float aDelta )
{
	myPlayer.Update( aDelta, myCamera );
	myEnemy.MoveTowards(Vector2f(512,512));
	myEnemy.Update(aDelta);
}

void App::FixedUpdate( const float aDelta )
{
	myPlayer.FixedUpdate(aDelta);
	myEnemy.FixedUpdate(aDelta);
}

void App::Render()
{
	myMap.Render( myCamera );
	myPlayer.Render();
	myEnemy.Render( myCamera );

#ifdef _DEBUG
	myPhysics.SetDrawCamera(&myCamera);
	myPhysics.DrawDebug();
#endif
}