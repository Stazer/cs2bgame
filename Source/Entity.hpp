#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Map ; // forward declaration

class Entity
{
	public :
		Entity ( Map & map ) ;
		Entity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ) ;
      virtual ~Entity () = default;

		void setTexture ( const sf::Texture & texture ) ;
		const sf::Texture * const getTexture ( ) const ;

		void setPosition ( const sf::Vector2f & position ) ;
		const sf::Vector2f & getPosition ( ) const ;

      void setRotation (float rotation);
      float getRotation ( ) const;

		Map & getMap ( ) ;
		const Map & getMap ( ) const ;

		void move ( const sf::Vector2f & offset ) ;

      void rotate (float offset);

		virtual void update ( const sf::Time & frameTime ) = 0 ;
      /*  */
		virtual void draw ( sf::RenderTarget & target ) const ;



	private :
		Map & map ;

		sf::Sprite sprite ;
} ;