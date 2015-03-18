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
Map::~Map ( )
{
    for ( auto iterator = this->entities.begin ( ) ; iterator != this->entities.end ( ) ; ++iterator )
    {
        delete * iterator ;
    }
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

void Map::clear ( )
{
    for ( auto iterator = this->entities.begin ( ) ; iterator != this->entities.end ( ) ; ++iterator )
    {
        delete * iterator ;
    }

    this->chunks.clear ( ) ;
    this->entities.clear ( ) ;
}

std::vector <Entity *> & Map::getEntities ( )
{
    return this->entities ;
}
const std::vector <Entity *> & Map::getEntities ( ) const
{
    return this->entities ;
}

void Map::update ( const sf::Time & frameTime )
{
    const sf::View & camera = this->game.getInterface ( ).getCamera ( ) ;
    const sf::Vector2f cameraPosition = camera.getCenter ( ) - ( 0.5f * camera.getSize ( ) ) ;

    // calculate the current chunk position in which the player is
    sf::Vector2i chunkPosition ( cameraPosition.x / camera.getSize ( ).x , cameraPosition.y / camera.getSize ( ).y ) ;

    // iterate through a 3x3 field around the current chunk position
    const sf::Vector2i maximumChunkPosition ( chunkPosition + sf::Vector2i ( 1 , 1 ) ) ;
    const sf::Vector2i minimumChunkPosition ( chunkPosition -= sf::Vector2i ( 1 , 1 ) ) ;

    for ( ; chunkPosition.x <= maximumChunkPosition.x ; ++chunkPosition.x )
    {
        for ( chunkPosition.y = minimumChunkPosition.y ; chunkPosition.y <= maximumChunkPosition.y ; ++chunkPosition.y )
        {
            // if there is not chunk at chunk position then insert a new chunk at this position
            // furthermore place a randomly choosen entity from our entity templates onto the map
            if ( this->chunks.find ( chunkPosition ) == this->chunks.end ( ) )
            {
                sf::Vector2f position ( chunkPosition.x * camera.getSize ( ).x , chunkPosition.y * camera.getSize ( ).y ) ;

                // add new chunk
                this->chunks [ chunkPosition ] = MapChunk ( * this , position , camera.getSize ( ) ) ;

                int limit = position.x + camera.getSize ( ).x ;

                if ( ! limit )
                    --limit ;

                position.x = position.x + rand ( ) % limit ;

                limit = position.y + camera.getSize ( ).y ;

                if ( ! limit )
                    --limit ;

                position.y = position.y + rand ( ) % limit ;

                // place the entity
                this->entities.push_back ( this->getGame ( ).getEnemyEntityTemplateManager ( ).createRandomEnemyEntity ( * this , position ) ) ;
            }
        }
    }

    // check every second for dead entities and remove them from the map, since they are not needed anymore
    if ( this->entityTimer.getElapsedTime ( ).asSeconds ( ) >= 1.0f )
    {
        for ( auto iterator = this->entities.begin ( ) ; iterator != this->entities.end ( ) ; ++iterator )
        {
            EnemyEntity * enemy = dynamic_cast <EnemyEntity *> ( * iterator ) ;

            if ( enemy && enemy->isDead ( ) )
            {
                delete * iterator ;
                iterator = this->entities.erase ( iterator ) ;
            }
        }

        entityTimer.restart ( ) ;
    }

    // update logic of entities
	for ( auto & entity : this->entities )
		entity->update ( frameTime ) ;
}
void Map::draw ( sf::RenderTarget & target ) const
{
    // draw chunks
	for ( auto & chunk : this->chunks )
		chunk.second.draw ( target ) ;

    // draw entites
	for ( auto & entity : this->entities )
		entity->draw ( target ) ;
}