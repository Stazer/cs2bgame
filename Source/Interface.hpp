#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "ResourceManager.hpp"

class AudioManager ;
class Game ;

class Interface
{
    public :
        Interface ( Game & game , sf::RenderWindow & window ) ;
        Interface ( const Interface & right ) = delete ;

		Interface & operator = ( const Interface & right ) = delete ;

        const sf::View & getCamera ( ) const ;

        sf::RenderWindow & getWindow ( ) ;
        const sf::RenderWindow & getWindow ( ) const ;

        /*  */
        void handle ( const sf::Event & event ) ;
        /*  */
        void update ( const sf::Time & frameTime ) ;
        /*  */
        void draw ( sf::RenderTarget & target ) ;

    private:
        Game & game ;

        sf::RectangleShape healthBar ;
        sf::Text statistics ;


        sf::RenderWindow & window ;
} ;
