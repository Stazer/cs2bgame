#pragma once

#include "MapArea.hpp"

class Map ;

class MapChunk
{
	public :
		MapChunk ( Map & map , const sf::Vector2f & position , const sf::Vector2f & size ) ;

		void draw ( sf::RenderTarget & target ) const ;

	private :
		std::vector <MapArea> areas ;

		static MapArea::TileType getRandomType ( ) ;
} ;
