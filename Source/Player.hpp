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
		Player ( Map & map , const sf::Vector2f & position , const sf::Texture & texture , unsigned int healthPoints , unsigned int maximumHealth ) ;

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
} ;
