#include "PowerUp.h"



PowerUp::PowerUp()
{
	x = 150;
	y = 360;
	x1 = 300;
	y1 = 250;
}


PowerUp::~PowerUp()
{
}

void PowerUp::setSpriteBombUp(string sprite)
{
	bombaUp.setSpriteSheet(sprite);
}

void PowerUp::setSpriteTenis(string sprite)
{
	tenis.setSpriteSheet(sprite);
}
