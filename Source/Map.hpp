/* for help look at:
 http://www.sfml-dev.org/tutorials/2.2/
 */

/* 
 
 */

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory> //unique_ptr
#include "ResourceManager.hpp"
#include "MapArea.hpp"


class Game ;
class Entity ;

class Map
{
	public :
		Map ( Game & game ) ;

      /* Justus and Brendan will implement */
		void update ( sf::Time & frameTime ) ;

		void draw ( sf::RenderTarget & target ) ;

	private :
      /*  */
		Game & game ;

      /* vector stores the map  "tiles" which are added at infinitum so that 
       the player can explore as much as they like and the map will automatically
       create new areas, think background picture */
		std::vector <MapArea> areas ;

      /* vector stores entity sprites, player entity, enemy entity, and static 
       entities like tress, rocks, and lava */
      std::vector <std::unique_ptr <Entity*> > entities ;
} ;
