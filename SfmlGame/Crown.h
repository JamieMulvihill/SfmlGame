#pragma once
#include "Player.h"

class Crown : public Sprite
{
public:
	Crown(Player* player);
	~Crown();

	void Update(float dt);
	bool GetPickedUp() { return isPickedUp; }
	void setPickedUp(bool pickUp) { isPickedUp = pickUp; }
	void collisionResponse(Sprite* sp);

private:
	bool isPickedUp;
	Player* player_;

};

