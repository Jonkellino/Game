#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "Sprite.h"

class b2World;
class b2Body;

class Enemy
{
public:
	Enemy(void);
	~Enemy(void);

	void Init(b2World* aWorld);
	void Update(const float aDelta);
	void FixedUpdate(const float aDelta);
	void Render();

	void MoveTowards(const Vector2f aMoveTarget);
	void RotateTowards(float aRotation);


private:
	b2Body* myBody;
	Sprite mySprite;

	Vector2f myMoveTarget;
	float myRotationTarget;
};

#endif