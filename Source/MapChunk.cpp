#include "MapChunk.hpp"

MapChunk::MapChunk ( Map & map , const sf::Vector2f & position , const sf::Vector2f & size )
{
    this->areas.push_back ( MapArea ( map , rand ( ) % 2 ? MapArea::Dirt : MapArea::Grass , position , size ) ) ;
}

void MapChunk::draw ( sf::RenderTarget & target ) const
{
    for ( auto & area : this->areas )
        area.draw ( target ) ;
}