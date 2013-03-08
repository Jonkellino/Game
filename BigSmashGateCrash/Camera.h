#pragma once

#include "Vector.h"

class Camera
{
public:
	Camera(void);
	~Camera(void);

public:
	const Vector2f const GetPosition() const { return myPosition; }
	void SetPosition( const Vector2f& aPosition ){ myPosition = aPosition; }
	void Move( const Vector2f& aMovement ){ myPosition += aMovement; }

private:
	Vector2f myPosition;
	//Vector2f mySize; TBI
};