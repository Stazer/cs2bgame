#include "Map.hpp"

Map::Map ( Game & game ) :
	game ( game )
{
}

void Map::update ( const sf::Time & frameTime )
{
	bool found = false ;
	
	for ( auto & area : this->areas )
	{
			
	}
}
void Map::draw ( sf::RenderTarget & target )
{
	for ( auto & area : this->areas )
		area.draw ( target ) ;
}
