#pragma once

#include "DynamicEntity.hpp"

class Player : public DynamicEntity
{
	private :
		
	public :
		Player ( Map & map ) ;
		Player ( Map & map , const sf::Vector2f & position , const sf::Texture & texture , unsigned int healthPoints , unsigned int maximumHealth ) ;
	
		void moveUp ( ) ;
		void moveDown ( ) ;
		void moveLeft ( ) ;
		void moveRight ( ) ;
		
		void update ( const sf::Time & frameTime ) const ;
} ;
