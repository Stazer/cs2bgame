#pragma once

#include "Entity.hpp"

class DynamicEntity : public Entity
{
	public :
		DynamicEntity ( Map & map ) ;
		DynamicEntity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture , unsigned int healthPoints , unsigned int maximumHealth ) ;
		
		void setMaximumHealth ( unsigned int maximumHealth ) ;
		unsigned int getMaximumHealth ( ) const ;
		
		void setHealth ( unsigned int health ) ;
		unsigned int getHealth ( ) const ;
		
		void decreaseHealth ( unsigned int health ) ;
		void increaseHealth ( unsigned int health ) ;
		
		void setAttackPoints ( unsigned int attackPoints ) ;
		unsigned int getAttackPoints ( ) const ;
		
		void setSpeedPoints ( unsigned int speedPoints ) ;
		unsigned int getSpeedPoints ( ) const ;
		
		void attack ( DynamicEntity & entity ) ;
	
	private :
		unsigned int health ;
		unsigned int maximumHealth ;
		
		unsigned int attackPoints ;
		unsigned int speedPoints ;
} ;
