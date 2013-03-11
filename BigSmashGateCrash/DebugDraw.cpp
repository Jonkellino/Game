#ifdef _DEBUG
#include "DebugDraw.h"
#include "PhysicsWrapper.h"
#include "Engine.h"
#include "Camera.h"

DebugDraw::DebugDraw()
{
	myDebugColour = ConstructColor( 255, 255, 255, 255 );

	testSprite.Load( "data/graphics/grass.png" );
	testSprite.Data().depth = -2.0f;
}

DebugDraw::~DebugDraw()
{
}

void DebugDraw::SetDrawCamera(Camera* aCamera)
{
	myCamera = aCamera;
}

void DebugDraw::DrawPolygon( const b2Vec2* vertices, int32 vertexCount, const b2Color& color )
{
	//Not used
}

void DebugDraw::DrawSolidPolygon( const b2Vec2* vertices, int32 vertexCount, const b2Color& color )
{
	Vector2f camPos = myCamera->GetPosition();

	SDL_Point* points = new SDL_Point[vertexCount+1];
	for( unsigned int index = 0; index < vertexCount; index++ )
	{
		points[index].x = ( vertices[index].x * PTM_RATIO ) - camPos.x;
		points[index].y = ( vertices[index].y * PTM_RATIO ) - camPos.y;
	}
	points[vertexCount] = points[0];

	EngineMessage message;
	message.myType = EngineMessageType::LINE_ARRAY_RENDER;
	message.lineArrayRender.verticeCount = vertexCount+1;
	message.lineArrayRender.myVertices = points;
	message.lineArrayRender.myColor = myDebugColour;
	EngineInstance->NotifyMessage(message);
	/*
	GraphicsEngine* engine = GraphicsEngine::GetInstance();
	if( engine )
	{
		for( unsigned int index = 0; index < static_cast< unsigned int >( vertexCount ); index++ )
		{
			hgeVertex vert = hgeVertex();
			vert.col = debugColor;
			vert.x = vertices[index].x * PTM_RATIO - myCameraPos.x;
			vert.y = vertices[index].y * PTM_RATIO - myCameraPos.y;
			myDebugVertices.push_back( vert );

			vert.col = debugColor;
			vert.x = vertices[(index+1)%vertexCount].x * PTM_RATIO - myCameraPos.x;
			vert.y = vertices[(index+1)%vertexCount].y * PTM_RATIO - myCameraPos.y;
			myDebugVertices.push_back( vert );
		}
	}
	*/
}

void DebugDraw::DrawCircle( const b2Vec2& center, float32 radius, const b2Color& color )
{
	//Not used
}

void DebugDraw::DrawSolidCircle( const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color )
{
	Vector2f pos = Vector2f( center.x, center.y );
	pos *= PTM_RATIO;
	pos = pos - myCamera->GetPosition();
	//pos += static_cast<Vector2f>(Engine::GetInstance()->GetWindowSize() / 2);
	float rad = radius * PTM_RATIO;
	//testSprite.Data().pos = pos;

	//testSprite.Render();

	SDL_Point* points = new SDL_Point[5];
	points[0].x = pos.x - rad;
	points[0].y = pos.y - rad;
	points[1].x = pos.x + rad;
	points[1].y = pos.y - rad;
	points[2].x = pos.x + rad;
	points[2].y = pos.y + rad;
	points[3].x = pos.x - rad;
	points[3].y = pos.y + rad;
	points[4].x = pos.x - rad;
	points[4].y = pos.y - rad;

	EngineMessage message;
	message.myType = EngineMessageType::LINE_ARRAY_RENDER;
	message.lineArrayRender.verticeCount = 5;
	message.lineArrayRender.myVertices = points;
	message.lineArrayRender.myColor = myDebugColour;
	EngineInstance->NotifyMessage(message);

	/*
	GraphicsEngine* engine = GraphicsEngine::GetInstance();
	if( engine )
	{
		const int segments = 16;
		int vertexCount = 0;
		int maxVertices = 0;
		const float32 increment = 2.0f * b2_pi / segments;
		float32 theta = 0.0f;

		for (int32 i = 0; i < segments ; i++)
		{
			b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));

			hgeVertex vert = hgeVertex();
			vert.col = debugColor;
			vert.x = v.x * PTM_RATIO - myCameraPos.x;
			vert.y = v.y * PTM_RATIO - myCameraPos.y;
			myDebugVertices.push_back( vert );

			theta += increment;
			v = center + radius * b2Vec2(cosf(theta), sinf(theta));

			vert.col = debugColor;
			vert.x = v.x * PTM_RATIO - myCameraPos.x;
			vert.y = v.y * PTM_RATIO - myCameraPos.y;
			myDebugVertices.push_back( vert );
		}

		b2Vec2 p = center + radius * axis;

		hgeVertex vert = hgeVertex();
		vert.col = debugColor;
		vert.x = center.x * PTM_RATIO - myCameraPos.x;
		vert.y = center.y * PTM_RATIO - myCameraPos.y;
		myDebugVertices.push_back( vert );

		vert.col = debugColor;
		vert.x = p.x * PTM_RATIO - myCameraPos.x;
		vert.y = p.y * PTM_RATIO - myCameraPos.y;
		myDebugVertices.push_back( vert );
	}
	*/
}

void DebugDraw::DrawSegment( const b2Vec2& p1, const b2Vec2& p2, const b2Color& color )
{
	//Not used
}

void DebugDraw::DrawTransform( const b2Transform& xf )
{
	//Not used
}
#endif