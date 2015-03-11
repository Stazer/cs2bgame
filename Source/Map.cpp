#include <cstdlib>
#include "Map.hpp"
#include "Game.hpp"
#include "Interface.hpp"
#include "MapArea.hpp"
#include "EnemyEntity.hpp"

Map::Map ( Game & game ) :
	game ( game )
{
    srand ( time ( nullptr ) ) ;

    EnemyEntity entity ( * this );

    entity.setTexture ( this->game.getTextureManager ( ).get ( "Player" ) ) ;
    entity.setMaximumHealth(1000) ;
    entity.setHealth(750) ;

    this->entities.push_back ( std::shared_ptr <Entity> ( new EnemyEntity ( entity ) ) ) ;
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
                this->chunks [ chunkPosition ] = std::shared_ptr <MapChunk> ( new MapChunk ( *this , sf::Vector2f ( chunkPosition.x * camera.getSize ( ).x , chunkPosition.y * camera.getSize ( ).y ) , camera.getSize () ) ) ;
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