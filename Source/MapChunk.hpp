#pragma once

#include "MapArea.hpp"

class Map ;

class MapChunk
{
	public :
        MapChunk ( ) = default ; // fix for std::tuple
		MapChunk ( Map & map , const sf::Vector2f & position , const sf::Vector2f & size ) ;

		void draw ( sf::RenderTarget & target ) const ;

	private :
		std::vector <MapArea> areas ;
} ;
