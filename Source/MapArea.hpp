/* for help look at:
 http://www.sfml-dev.org/tutorials/2.2/
 */

#pragma once

#include <vector>

class MapArea
{
	public :
		enum TileType
		{
			Snow ,
			Grass ,
			Dirt ,
         Lava
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

      /* vector holds all pictures (sprites) that will make up the map */
		std::vector <sf::Sprite> tiles ;
} ;
