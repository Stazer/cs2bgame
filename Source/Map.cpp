#include <cstdlib>
#include "Map.hpp"
#include "Game.hpp"
#include "Interface.hpp"
#include "MapArea.hpp"

Map::Map ( Game & game ) :
	game ( game )
{
    srand ( time ( nullptr ) ) ;
}

const Game & Map::getGame ( ) const
{
    return this->game ;
}
Game & Map::getGame ( )
{
    return this->game ;
}

void Map::update ( const sf::Time & frameTime )
{
    const sf::View & camera = this->game.getInterface().getCamera() ;
    const sf::Vector2f cameraPosition = camera.getCenter ( ) - ( 0.5f * camera.getSize ( ) ) ;

    sf::Vector2i chunkPosition ( cameraPosition.x / camera.getSize ( ).x , cameraPosition.y / camera.getSize ( ).y ) ;

    const sf::Vector2i maximumChunkPosition ( chunkPosition + sf::Vector2i ( 1 , 1 ) ) ;
    const sf::Vector2i minimumChunkPosition ( chunkPosition -= sf::Vector2i ( 1 , 1 ) ) ;

    for ( ; chunkPosition.x <= maximumChunkPosition.x ; ++chunkPosition.x )
    {
        for ( chunkPosition.y = minimumChunkPosition.y ; chunkPosition.y <= maximumChunkPosition.y ; ++chunkPosition.y )
        {
            if ( this->areas.find ( chunkPosition ) == this->areas.end ( ) )
            {
                this->areas [ chunkPosition ] = std::shared_ptr <MapArea> ( new MapArea ( *this , rand ( ) % 2 ? MapArea::Dirt : MapArea::Grass , sf::Vector2f ( chunkPosition.x * camera.getSize ( ).x , chunkPosition.y * camera.getSize ( ).y ) , camera.getSize () ) ) ;
            }
        }
    }
}
void Map::draw ( sf::RenderTarget & target )
{
	for ( auto & area : this->areas )
		area.second->draw ( target ) ;
}