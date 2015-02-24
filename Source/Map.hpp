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

		void update ( sf::Time & frameTime ) ;
		void draw ( sf::RenderTarget & target ) ;

	private :
      /*  */
		Game & game ;

		std::vector <MapArea> areas ;
      /*  */
      std::vector <std::unique_ptr <Entity*> > tiles ;
} ;
