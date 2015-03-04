#include "MapArea.hpp"

MapArea::MapArea ( MapArea::TileType type , const sf::Vector2f & position , const sf::Vector2f & size ) :
	type ( type ) ,
	position ( position ) ,
	size ( size )
{
}
		
MapArea::TileType MapArea::getType ( ) const
{
	return this->type ;
}
const sf::Vector2f & MapArea::getPosition ( ) const
{
	return this->position ;
}
const sf::Vector2f & MapArea::getSize ( ) const
{
	return this->size ;
}

/*  */
void MapArea::draw ( sf::RenderTarget & target ) const
{
	for ( auto & tile : this->tiles )
		target.draw ( tile ) ;
}
