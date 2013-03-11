#pragma once

#include "Vector.h"

class Camera
{
public:
	Camera(void);
	~Camera(void);

public:
	void Init(const Vector2f aScreenSize) { mySize = aScreenSize; }
	const Vector2f GetPosition() const { return myPosition; }
	const Vector2f GetScreenCenter() const { return myPosition + mySize * 0.5f; }
	void SetPosition( const Vector2f& aPosition ){ myPosition = aPosition; }
	void Move( const Vector2f& aMovement ){ myPosition += aMovement; }

private:
	Vector2f myPosition;
	Vector2f mySize;
};