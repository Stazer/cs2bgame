#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Application
{
	public :
        int main ( const std::vector <std::string> & arguments ) ;

	private :
        sf::RenderWindow window ;
        sf::Clock frameClock ;
} ;