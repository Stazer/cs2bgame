#include <cstdlib>
#include "Map.hpp"
#include "Game.hpp"
#include "Interface.hpp"
#include "MapArea.hpp"
#include "EnemyEntity.hpp"

Map::Map ( Game & game ) :
	game ( game )
{
}

const Game & Map::getGame ( ) const
{
    return this->game ;
}
Game & Map::getGame ( )
{
    return this->game ;
}

const Player & Map::getPlayer ( ) const
{
    return this->game.getPlayer ( ) ;
}
Player & Map::getPlayer ( )
{
    return this->game.getPlayer ( ) ;
}

#include <iostream>

void Map::update ( const sf::Time & frameTime )
{
    const sf::View & camera = this->game.getInterface ( ).getCamera ( ) ;
    const sf::Vector2f cameraPosition = camera.getCenter ( ) - ( 0.5f * camera.getSize ( ) ) ;

    sf::Vector2i chunkPosition ( cameraPosition.x / camera.getSize ( ).x , cameraPosition.y / camera.getSize ( ).y ) ;

    const sf::Vector2i maximumChunkPosition ( chunkPosition + sf::Vector2i ( 1 , 1 ) ) ;
    const sf::Vector2i minimumChunkPosition ( chunkPosition -= sf::Vector2i ( 1 , 1 ) ) ;

    for ( ; chunkPosition.x <= maximumChunkPosition.x ; ++chunkPosition.x )
    {
        for ( chunkPosition.y = minimumChunkPosition.y ; chunkPosition.y <= maximumChunkPosition.y ; ++chunkPosition.y )
        {
            if ( this->chunks.find ( chunkPosition ) == this->chunks.end ( ) )
            {
                sf::Vector2f position ( chunkPosition.x * camera.getSize ( ).x , chunkPosition.y * camera.getSize ( ).y ) ;

                this->chunks [ chunkPosition ] = std::shared_ptr <MapChunk> ( new MapChunk ( *this , position , camera.getSize ( ) ) ) ;

                // spawn only 1
                int limit = position.x + camera.getSize ( ).x ;

                if ( ! limit )
                    --limit ;

                position.x = position.x + rand ( ) % limit ;

                limit = position.y + camera.getSize ( ).y ;

                if ( ! limit )
                    --limit ;

                position.y = position.y + rand ( ) % limit ;

                this->entities.push_back ( std::shared_ptr <Entity> ( this->getGame ( ).getEnemyEntityTemplateManager ( ).createRandomEnemyEntity ( * this , position ) ) ) ;

            }
        }
    }

	for ( auto & entity : this->entities )
		entity->update ( frameTime ) ;
}
void Map::draw ( sf::RenderTarget & target ) const
{
	for ( auto & chunk : this->chunks )
		chunk.second->draw ( target ) ;

	for ( auto & entity : this->entities )
		entity->draw ( target ) ;
}