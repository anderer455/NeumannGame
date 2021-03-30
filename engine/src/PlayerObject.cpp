#include "../include/PlayerObject.hpp"

namespace engine
{
	PlayerObject::PlayerObject()
	{
		this->circle.setFillColor(sf::Color::Green);
		this->circle.setRadius(25);
		this->owner = 1;
		this->value = 1;
		
	}

	void PlayerObject::setPos(int xPos, int yPos)
	{
		this->circle.setPosition(xPos * tileSize, yPos * tileSize);
	}

	
	
	void PlayerObject::drawObj(sf::RenderWindow *RWindow)
	{
		RWindow->draw(this->circle);
	}
	void PlayerObject::updateObj()
	{

	}
	void PlayerObject::move(int x, int y)
	{
		this->setPos(x, y);
	}
}