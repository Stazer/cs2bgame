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
        Interface ( Game & game , const sf::RenderTarget & target ) ;

        const sf::View & getCamera ( ) const ;
        const sf::RenderTarget & getTarget ( ) const ;

        /*  */
        void handle ( const sf::Event & event ) ;
        /*  */
        void update ( const sf::Time & frameTime ) ;
        /*  */
        void draw ( sf::RenderTarget & target ) ;

    private:
        Game & game ;

        sf::RectangleShape healthBar ;

        const sf::RenderTarget & target ;
} ;
