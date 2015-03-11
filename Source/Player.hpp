#pragma once

#include "DynamicEntity.hpp"

class Player : public DynamicEntity
{
	private :
        /* this is the amount of pixels the image will move everytime a key is pressed and
        the program is updated */
        sf::Vector2f offset;

	public :
		Player ( Map & map ) ;
		Player ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ,
                 unsigned int healthPoints , unsigned int maximumHealth, unsigned int attackPoints,
                 unsigned int speedPoints ) ;
} ;