#include "Inventory.h"
#include "Engine.h"

Inventory::Inventory(void)
{
	myBackground.Load( "data/graphics/inventory/inventoryscreen.png" );
	const Vector2i screenSize = Engine::GetInstance()->GetWindowSize();
	myBackground.Data().pos = screenSize / 2;
	myBackground.Data().depth = -1.1f;

	for( unsigned char index = 0; index < myNumberOfItemSlots; index++ )
	{
		mySlots[index] = NULL;
	}
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
	for( unsigned int index = 0; index < myNumberOfItemSlots; index++ )
	{
		if( mySlots[index] != NULL )
		{
			mySlots[index]->myInventoryIcon.Render();
		}
	}
}

bool Inventory::AddItem( Inventable* anItem )
{
	for( unsigned int index = 0; index < myNumberOfItemSlots; index++ )
	{
		if( mySlots[index] == NULL )
		{
			mySlots[index] = anItem;
			unsigned char xOffset = index%2;
			unsigned char yOffset = index/2;
			mySlots[index]->myInventoryIcon.Data().pos = Vector2f( 850 + 120 * xOffset, 350 + 100 * yOffset );
			mySlots[index]->myInventoryIcon.Data().depth = -1.2f;
			return true;
		}
	}
	return false;
}