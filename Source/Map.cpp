#include "Map.hpp"
#include <cstdlib>

Map::Map ( const TextureManager & textureManager )
{
    srand ( time ( NULL ) ) ;

    for ( unsigned int x = 0 ; x < 16 ; ++x )
    {
        for ( unsigned int y = 0 ; y < 16 ; ++y )
        {
            unsigned int tile = rand ( ) % 16 ;

            sf::Sprite sprite ;
            sprite.setTexture( textureManager.get ( "GrassTiles" ) ) ;
            sprite.setTextureRect ( sf::IntRect ( tile * 64 , 0 , 64 , 32 ) ) ;
            sprite.setPosition ( x * 64 , y * 32 ) ;

            this->sprites.push_back ( sprite ) ;
        }
    }
    for ( unsigned int x = 0 ; x < 16 ; ++x )
    {
        for ( unsigned int y = 0 ; y < 16 ; ++y )
        {
            unsigned int tile = rand ( ) % 16 ;

            sf::Sprite sprite ;
            sprite.setTexture( textureManager.get ( "GrassTiles" ) ) ;
            sprite.setTextureRect ( sf::IntRect ( tile * 64 , 0 , 64 , 32 ) ) ;
            sprite.setPosition ( x * 64 + 32 , y * 32 + 16 ) ;

            this->sprites.push_back ( sprite ) ;
        }
    }
}

void Map::update ( const sf::Clock & frametime )
{

}

void Map::draw ( sf::RenderTarget & target , sf::RenderStates states ) const
{
    for ( auto & sprite : this->sprites )
    {
        target.draw ( sprite ) ;
    }
}