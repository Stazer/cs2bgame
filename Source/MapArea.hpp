#pragma once

#include <vector>

class MapArea
{
	public :
		enum TileType
		{
			Snow ,
			Grass ,
			Dirt
		} ;
		
		MapArea ( TileType type , const sf::Vector2f & position , const sf::Vector2f & size ) ;
		
		TileType getType ( ) const ;
		const sf::Vector2f & getPosition ( ) const ;
		const sf::Vector2f & getSize ( ) const ;

      /*  */
		void draw ( sf::RenderTarget & target ) const ;
	
	private :
		TileType type ;
	
		sf::Vector2f position ;
		sf::Vector2f size ;
	
		std::vector <sf::Sprite> tiles ;
} ;
