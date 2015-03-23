#include "MapArea.hpp"
#include "Map.hpp"
#include "Game.hpp"

MapArea::MapArea ( Map & map , MapArea::TileType type , const sf::Vector2f & position , const sf::Vector2f & size ) :
	map ( map ) ,
	type ( type ) ,
	position ( position ) ,
	size ( size )
{
    sf::Texture * texture = nullptr ;

    // set the type of the texture by using the MapArea::TileType
    if ( type == MapArea::Dirt )
        texture = & map.getGame ( ).getTextureManager ( ).get ( "Dirt" ) ;
    else if ( type == MapArea::Snow )
        texture = & map.getGame ( ).getTextureManager ( ).get ( "Snow" ) ;
    else if ( type == MapArea::Sand )
        texture = & map.getGame ( ).getTextureManager ( ).get ( "Sand" ) ;
    else
        texture = & map.getGame ( ).getTextureManager ( ).get ( "Grass" ) ;

    const float maxPositionX = position.x + size.x ;
    const float maxPositionY = position.y + size.y ;

    // fill the area with the texture
    for ( float x = position.x ; x < maxPositionX ; x += texture->getSize ( ).x )
    {
        for ( float y = position.y ; y < maxPositionY ; y += texture->getSize ( ).y )
        {
            sf::Sprite sprite ( * texture ) ;

            sprite.setPosition ( sf::Vector2f ( x , y ) ) ;

            const float tempX = x + texture->getSize ( ).x ;
            const float tempY = y + texture->getSize ( ).y;

            sf::Vector2i newSize ( texture->getSize ( ).x , texture->getSize ( ).y ) ;

            if ( tempX > maxPositionX )
                newSize.x -= tempX - maxPositionX ;
            if ( tempY > maxPositionY )
                newSize.y -= tempY - maxPositionY ;

            sprite.setTextureRect ( sf::IntRect ( sf::Vector2i ( ), newSize ) ) ;

            // add the new tile to the vector
            this->tiles.push_back ( sprite ) ;
        }
    }
}
MapArea::MapArea ( const MapArea & right ) :
	map ( right.map ) ,
	type ( right.type ) ,
	position ( right.position ) ,
	size ( right.size ) ,
	tiles ( right.tiles )
{
}

MapArea & MapArea::operator = ( const MapArea & right )
{
	this->type = right.type ;
	this->position = right.position ;
	this->size = right.size ;
	this->tiles = right.tiles ;
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

MapArea::TileType MapArea::getRandomType ( )
{
    return static_cast <MapArea::TileType> ( std::rand ( ) % MapArea::MAX );
}
