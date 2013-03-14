#include "Inventory.h"
#include "Engine.h"

Inventory::Inventory(void)
{
	myBackground.Load( "data/graphics/inventory/inventoryscreen.png" );
	const Vector2i screenSize = Engine::GetInstance()->GetWindowSize();
	myBackground.Data().pos = screenSize / 2;
	myBackground.Data().depth = -1.1f;
}

Inventory::~Inventory(void)
{
}

void Inventory::Update( const float aDelta )
{
}

void Inventory::Render()
{
	myBackground.Render();
}