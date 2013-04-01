#include "Equipment.h"
#include "Fist.h"

Equipment::Equipment(void)
{
	myFist = new Fist();
	mySlots[EQUIPSLOT_WEAPON] = myFist;
	mySlots[EQUIPSLOT_USEABLE] = NULL;
}

Equipment::~Equipment(void)
{
}

void Equipment::Render()
{
	for( unsigned char index = 0; index < mySlots.size(); index++ )
	{
		unsigned char xOffset = index%2;
		unsigned char yOffset = index/2;
		if( mySlots[index] != NULL )
		{
			mySlots[index]->myInventoryIcon.Data().pos = Vector2f( 850 + 120 * xOffset, 150 + 100 * yOffset );
			mySlots[index]->myInventoryIcon.Data().depth = -1.2f;
			mySlots[index]->myInventoryIcon.Render();
		}
	}
}

void Equipment::Use( EQUIPSLOTS aSlot )
{
	if( mySlots[aSlot] != NULL )
	{
		mySlots[aSlot]->Use();
	}
}