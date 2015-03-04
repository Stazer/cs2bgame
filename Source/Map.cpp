#include "Map.hpp"

Map::Map ( Game & game ) :
	game ( game )
{
}

void Map::update ( sf::Time & frameTime )
{
}
void Map::draw ( sf::RenderTarget & target )
{
	for ( auto & area : this->areas )
		area.draw ( target ) ;
}
