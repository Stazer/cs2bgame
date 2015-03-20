#include "Application.hpp"
#include "ResourceManager.hpp"
#include "AudioManager.hpp"
#include "Game.hpp"
#include "Map.hpp"

int Application::main ( const std::vector <std::string> & arguments )
{
    try
    {
        // initialize random number generator
        srand ( time ( nullptr ) ) ;

        // setup frametime
        sf::Clock frameClock ;
        sf::Time frameTime ;

        // setup opengl window
        sf::RenderWindow window ( sf::VideoMode ( 1024 , 768 , 32 ) , "CS2BGame" ) ;

        // setup resource managers
        AudioManager audioManager ;
        TextureManager textureManager ;
        FontManager fontManager ;

        // fill resource managers with resources
        audioManager.getSoundBufferManager ( ).add ( "Data/Hit.ogg" ) ;
        textureManager.add ( "Data/Dirt.png" ) ;
        textureManager.add ( "Data/Grass.png" ) ;
        textureManager.add ( "Data/Sand.png" ) ;
        textureManager.add ( "Data/Snow.png" ) ;
        textureManager.add ( "Data/Player.png" ) ;
        textureManager.add ( "Data/Mech.png" ) ;
        textureManager.add ( "Data/BigMech.png" ) ;
        textureManager.add ( "Data/Instructions.png" ) ;
        fontManager.add ( "Data/Arial.ttf" ) ;

        // create game object
        Game game ( textureManager , audioManager , fontManager , window ) ;

        // gameloop
        while ( window.isOpen ( ) )
        {
            // handle frametime
            frameTime = frameClock.restart ( ) ;

            // handle events
            sf::Event event ;
            while ( window.pollEvent ( event ) )
            {

                if ( event.type == sf::Event::Closed )
                    window.close ( ) ;

                game.handle ( event ) ;
            }

            // update game logic
            game.update ( frameTime ) ;

            // clear the window and draw our game
            window.clear ( ) ;
            game.draw ( window ) ;
            window.display ( ) ;
        }
    }
    catch ( const std::exception & exception )
    {
        std::cout << exception.what ( ) ;
        return -1 ;
    }

    return 0 ;
}
