#include "MapChunk.hpp"

MapChunk::MapChunk ( Map & map , const sf::Vector2f & position , const sf::Vector2f & size )
{
    // insert four MapAreas into the chunk, with a random size
    sf::Vector2f firstAreaSize ( std::rand ( ) % static_cast <int> ( size.x ) , std::rand ( ) % static_cast <int> ( size.y ) ) ;

    sf::Vector2f tempSize = firstAreaSize ;
    sf::Vector2f tempPosition = position ;

    this->areas.push_back ( MapArea ( map , MapArea::getRandomType ( ) , tempPosition , tempSize ) ) ;

    tempPosition.x += firstAreaSize.x ;
    tempSize.x = size.x - firstAreaSize.x ;

    this->areas.push_back ( MapArea ( map , MapArea::getRandomType ( ) , tempPosition , tempSize ) ) ;

    tempSize = firstAreaSize ;
    tempPosition = position ;

    tempPosition.y += firstAreaSize.y ;
    tempSize.y = size.y - firstAreaSize.y ;

    this->areas.push_back ( MapArea ( map , MapArea::getRandomType ( ) , tempPosition , tempSize ) ) ;

    tempPosition.x += firstAreaSize.x ;
    tempSize.x = size.x - firstAreaSize.x ;

    this->areas.push_back ( MapArea ( map , MapArea::getRandomType ( ) , tempPosition , tempSize ) ) ;
}

void MapChunk::draw ( sf::RenderTarget & target ) const
{
    for ( auto & area : this->areas )
        area.draw ( target ) ;
}
