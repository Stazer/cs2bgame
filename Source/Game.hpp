#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"

class Game
{
	public :
		void handle ( const sf::Event & event ) ;
		void update ( const sf::Time & frameTime ) ;
		void draw ( sf::RenderTarget & target ) ;

    private :
    	
} ;
