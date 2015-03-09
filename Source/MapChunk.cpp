#include "MapChunk.hpp"

#include <iostream>

MapArea::TileType getType ( )
{
    return static_cast <MapArea::TileType> ( rand ( ) % MapArea::MAX );
}

MapChunk::MapChunk ( Map & map , const sf::Vector2f & position , const sf::Vector2f & size )
{
    sf::Vector2f firstAreaSize ( rand ( ) % static_cast <int> ( size.x ) , rand ( ) % static_cast <int> ( size.y ) ) ;

    sf::Vector2f tempSize = firstAreaSize ;
    sf::Vector2f tempPosition = position ;

    /*this->areas.push_back ( MapArea ( map , getType ( ) , tempPosition , tempSize ) ) ;

    tempPosition.x += firstAreaSize.x ;
    tempSize.x = size.x - firstAreaSize.x ;

    this->areas.push_back ( MapArea ( map , getType ( )  , tempPosition  , tempSize ) ) ;

    tempPosition.x = position.x ;

    tempPosition.y += firstAreaSize.y ;
    tempSize.y = size.y - firstAreaSize.y ;

    this->areas.push_back ( MapArea ( map , getType ( )  , tempPosition  , tempSize ) ) ;

    tempPosition.x += firstAreaSize.x ;
    tempSize.x = size.x - firstAreaSize.x ;

    this->areas.push_back ( MapArea ( map , getType ( )  , tempPosition  , tempSize ) ) ;*/

    /*tempPosition.x = position.x ;
    tempPosition.y += size.y - tempSize.y ;
    tempSize.y = size.y - tempSize.y ;

    this->areas.push_back ( MapArea ( map , getType ( )  , tempPosition  , tempSize ) ) ;*/

    //this->areas.push_back ( MapArea ( map , rand ( ) % 2 ? MapArea::Dirt : MapArea::Grass , tempPosition  , tempSize ) ) ;
}

void MapChunk::draw ( sf::RenderTarget & target ) const
{
    for ( auto & area : this->areas )
        area.draw ( target ) ;
}