#include "App.h"
#include "SDL\SDL.h"
#include "Keyboard.h"
#include "Engine.h"

App::App(void)
{
	myFPSTextBuffer = new char[16];
	myFPSTextBuffer[0] = '\0';
	myFPSText.Load(myFPSTextBuffer, "FPSText");
	myFPSText.Data().pos = Vector2i(0,0);
	myFPSText.Data().hotspot = Vector2f(0,0);
	myFPSText.Data().depth = -1000.f;

	myCamera.Init(static_cast<Vector2f>(Engine::GetInstance()->GetWindowSize()));

	myLineTestBuffer = new SDL_Point[5]; //BUGG, MEMLEAK 
	for(int i = 0; i < 5; ++i) 
	{
		myLineTestBuffer[i].x = rand()% 1680;
		myLineTestBuffer[i].y = rand()% 1080;
	}

	b2World* currentWorld = myPhysics.GetWorld();

	myPlayer.Init(currentWorld);

	//b2CircleShape* shape = new b2CircleShape();
	//shape->m_radius =  100 / 2.0f / PTM_RATIO;

	//b2Filter filter;

	//b2FixtureDef fixtureDef;
	//fixtureDef.shape = shape;
	//fixtureDef.filter = filter;

	//b2BodyDef bodyDef;

	//b2Body* body = currentWorld->CreateBody( &bodyDef );
	//body->CreateFixture( &fixtureDef );
	//body->SetTransform( b2Vec2( 100 / PTM_RATIO, 100 / PTM_RATIO ), 0 );
	//delete fixtureDef.shape;

	myMap.Init(currentWorld);
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
	Update( aDelta );

	static const float physicsFps = 30;
	static const float timeStep = 1 / physicsFps;
	static float physicsTimer = 0;
	physicsTimer += aDelta;
	while( physicsTimer >= timeStep )
	{
		physicsTimer -= timeStep;
		FixedUpdate( timeStep );
		myPhysics.Step( timeStep );
	}

	myPlayer.Update( aDelta, myCamera );
	myMap.Render( myCamera );
	myPlayer.Render();

	EngineMessage message;
	message.myType = EngineMessageType::LINE_ARRAY_RENDER;
	message.lineArrayRender.verticeCount = 5;
	message.lineArrayRender.myVertices = myLineTestBuffer;
	message.lineArrayRender.myColor = ConstructColor(255, 255, 255, 255);
	//EngineInstance->NotifyMessage(message);

#ifdef _DEBUG
	myPhysics.SetDrawCamera(&myCamera);
	myPhysics.DrawDebug();
#endif

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
}

void App::FixedUpdate( const float aDelta )
{
	myPlayer.FixedUpdate(aDelta);
}