#ifdef _DEBUG
#include "DebugDraw.h"
#include "PhysicsWrapper.h"

DebugDraw::DebugDraw()
{
	myDebugColour = ConstructColor( 255, 255, 255, 255 );

	testSprite.Load( "data/graphics/grass.png" );
	testSprite.Data().depth = -2.0f;
}

DebugDraw::~DebugDraw()
{
}

void DebugDraw::DrawDebugData()
{
	/*
	GraphicsEngine::GetInstance()->RenderPhysics( myDebugVertices );
	myDebugVertices.clear();
	*/
}

void DebugDraw::DrawPolygon( const b2Vec2* vertices, int32 vertexCount, const b2Color& color )
{
	//Not used
}

void DebugDraw::DrawSolidPolygon( const b2Vec2* vertices, int32 vertexCount, const b2Color& color )
{
	int fia = 9;
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
	testSprite.Data().pos = pos;
	testSprite.Render();
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