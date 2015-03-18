#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <functional>
#include "ResourceManager.hpp"
#include "MapChunk.hpp"
#include "Player.hpp"

class Game ;
class Entity ;

namespace std
{
    template <>
    struct hash <sf::Vector2i>
    {
        std::size_t operator ( ) ( const sf::Vector2i & vector ) const
        {
            std::size_t hashX = std::hash <int> ( ) ( vector.x ) ;
            std::size_t hashY = std::hash <int> ( ) ( vector.y ) ;

            return hashX ^ hashY ;
        }
    } ;
}

class Map
{
	public :
		Map ( Game & game ) ;
		~Map ( ) ;

		Map ( const Map & map ) = delete ;
		Map & operator = ( const Map & map ) = delete ;

		const Game & getGame ( ) const ;
		Game & getGame ( ) ;

		const Player & getPlayer ( ) const ;
		Player & getPlayer ( ) ;

		void clear ( ) ;

        std::vector <Entity *> & getEntities ( ) ;
        const std::vector <Entity *> & getEntities ( ) const ;

        /* Justus and Brendan will implement */
		void update ( const sf::Time & frameTime ) ;

		void draw ( sf::RenderTarget & target ) const ;

	private :
		Game & game ;

		sf::Clock entityTimer ;

        /* stores chunks with position of its key, for making the random map generation
        possible */
		std::unordered_map <sf::Vector2i , MapChunk> chunks ;

        /* vector stores entity sprites, player entity, enemy entity, and static
        entities like tress, rocks, and lava */
        std::vector <Entity *> entities ;
} ;
