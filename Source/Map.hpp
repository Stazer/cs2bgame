#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "ResourceManager.hpp"

class Map : public sf::Drawable
{
	public :
		Map ( const TextureManager & textureManager ) ;

		void update ( const sf::Clock & frametime ) ;

	private :
		void draw ( sf::RenderTarget & target , sf::RenderStates states ) const ;

		std::vector <sf::Sprite> sprites ;
} ;
