/*
 Dynamic Entities include the player and enemies. These entities must be able to move, rotate, and attack.
 for help look at:
 http://www.sfml-dev.org/tutorials/2.2/
 */

#pragma once

#include "Entity.hpp"

class DynamicEntity : public Entity
{
	public :
		DynamicEntity ( Map & map ) ;
		DynamicEntity ( Map & map , const sf::Vector2f & position ,
                        const sf::Texture & texture , unsigned int healthPoints ,
                        unsigned int maximumHealth, unsigned int attackPoints, unsigned int speedPoints ) ;
        virtual ~DynamicEntity () = default;

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

        /* sets the offset y to -(speedPoints), so that the entity will move up the screen */
		void moveUp ( ) ;

        /* sets the offset y to +(speedPoints), so that the entity will move down the screen */
        void moveDown ( ) ;

        /* sets the offset x to -(speedPoints), so that the entity will move left on the screen */
		void moveLeft ( ) ;

        /* sets the offset x to +(speedPoints), so that the entity will move right on the screen */
		void moveRight ( ) ;

        /* will call the move method of the classs; the frameTime parameter is
        multiplied by the offset (measured in pixels) and updates the
        player position */
		void update ( const sf::Time & frameTime ) ;

		void attack ( DynamicEntity & entity ) ;

	private :
		unsigned int health = 0 ;
		unsigned int maximumHealth = 0 ;

		unsigned int attackPoints = 0 ;
		unsigned int speedPoints = 0 ;

		sf::Vector2f offset ;
} ;