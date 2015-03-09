/* for help look at:
 http://www.sfml-dev.org/tutorials/2.2/
 */

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Map ;

class MapArea
{
	public :
		enum TileType
		{
			Snow = 0 ,
			Grass ,
			Dirt ,
			Sand ,

			MAX
		} ;

		MapArea ( Map & map , TileType type , const sf::Vector2f & position , const sf::Vector2f & size ) ;

		TileType getType ( ) const ;
		const sf::Vector2f & getPosition ( ) const ;
		const sf::Vector2f & getSize ( ) const ;

      /*  */
		void draw ( sf::RenderTarget & target ) const ;

		static MapArea::TileType getRandomType ( ) ;

	private :
        Map & map ;

		TileType type ;

		sf::Vector2f position ;
		sf::Vector2f size ;

      /* vector holds all pictures (sprites) that will make up the map */
		std::vector <sf::Sprite> tiles ;
} ;
