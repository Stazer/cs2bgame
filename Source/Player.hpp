#pragma once

#include "DynamicEntity.hpp"

class Player : public DynamicEntity
{
	private :
        sf::Clock healthTimer ;

	public :
		Player ( Map & map ) ;
		Player ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ,
                 unsigned int healthPoints , unsigned int maximumHealth, unsigned int attackPoints,
                 unsigned int speedPoints ) ;

        void update ( const sf::Time & frameTime ) ;
} ;