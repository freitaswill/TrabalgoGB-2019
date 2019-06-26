#include "PowerUp.h"



PowerUp::PowerUp()
{
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
