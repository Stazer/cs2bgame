#include "Application.hpp"
#include "ResourceManager.hpp"
#include "Map.hpp"

int Application::main ( const std::vector <std::string> & arguments )
{
	TextureManager textureManager ;

	textureManager.add ( "Data/GrassTiles.png" ) ;
	textureManager.add ( "Data/SnowTiles.png" ) ;

    Map map ( textureManager );

    this->window.create ( sf::VideoMode ( 1024 , 768 , 32 ) , "Map Test" ) ;

    while ( this->window.isOpen ( ) )
    {
        sf::Time frametime = this->frameClock.restart ( ) ;

        sf::Event event ;

        while ( this->window.pollEvent ( event ) )
        {

            if ( ( event.type == sf::Event::Closed ) ||
                 ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) )
                this->window.close ( ) ;
            else if ( event.type == sf::Event::MouseMoved )
                std::cout << "( " << sf::Mouse::getPosition ( this->window ).x << "|" << sf::Mouse::getPosition ( this->window ).y << ")\n" ;
        }

        // camera movement
        /*sf::Vector2f offset ;

        if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Right ) )
            offset.x = 2 ;
        else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Left ) )
            offset.x = -2 ;

        if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Up ) )
            offset.y = -2 ;
        else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Down ) )
            offset.y = 2 ;

        offset.x *= frametime.asMilliseconds ( ) ;
        offset.y *= frametime.asMilliseconds ( ) ;*/

        this->window.

        this->window.clear ( ) ;

        this->window.draw ( map ) ;

        this->window.display ( ) ;
    }

    return 0 ;
}
