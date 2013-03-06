#pragma once

#include "Vector.h"

class Camera
{
public:
	Camera(void);
	~Camera(void);

public:
	const Vector2f GetPosition(){ return myPosition; }
	void SetPosition( const Vector2f& aPosition ){ myPosition = aPosition; }

private:
	Vector2f myPosition;
	//Vector2f mySize; TBI
};