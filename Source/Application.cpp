#include "Application.hpp"
#include "ResourceManager.hpp"
#include "AudioManager.hpp"
#include "Game.hpp"
#include "Map.hpp"

int Application::main ( const std::vector <std::string> & arguments )
{
    sf::Clock frameClock ;
    sf::Time frameTime ;

    sf::RenderWindow window ( sf::VideoMode ( 1024 , 768 , 32 ) , "CS2BGame" ) ;

    AudioManager audioManager ;
	TextureManager textureManager ;

	textureManager.add ( "Data/Dirt.png" ) ;
	textureManager.add ( "Data/Grass.png" ) ;
	textureManager.add ( "Data/Sand.png" ) ;
	textureManager.add ( "Data/Snow.png" ) ;
	textureManager.add ( "Data/Player.png" ) ;

	Game gameState ( textureManager , audioManager , window.getView ( ) ) ;

    while ( window.isOpen ( ) )
    {
        frameTime = frameClock.restart ( ) ;

        sf::Event event ;
        while ( window.pollEvent ( event ) )
        {

            if ( ( event.type == sf::Event::Closed ) ||
                 ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) )
                window.close ( ) ;

        	gameState.handle ( event ) ;
        }

       	gameState.update ( frameTime ) ;

        window.clear ( ) ;
        gameState.draw ( window ) ;
        window.display ( ) ;
    }

    return 0 ;
}
