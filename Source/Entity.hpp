#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class Entity : public sf::Drawable
{
	public :
		Entity ( const sf::Vector2f & Position = sf::Vector2f ( ) ) ;
        virtual ~Entity ( ) = default ;

        void setTexture ( const TextureManager & textureManager , const std::string & name ) ;
        void setTexture ( const sf::Texture & texture ) ;
        const sf::Texture * const getTexture ( ) const ;

        void setPositionX ( float positionX ) ;
        void setPositionY ( float positionY ) ;
        void setPosition ( float positionX , float positionY ) ;
        void setPosition ( const sf::Vector2f & position ) ;
        const sf::Vector2f & getPosition ( ) const ;

		void increaseHealth ( unsigned int health ) ;
		void decreaseHealth ( unsigned int health ) ;

		void setHealth ( unsigned int health ) ;
		unsigned int getHealth ( ) const ;

		void setMaximumHealth ( unsigned int maximumHealth ) ;
		unsigned int getMaximumHealth ( ) const ;

		bool isDead ( ) const ;
		bool isAlive ( ) const ;

		virtual void update ( ) = 0 ;

	private :
		void draw ( sf::RenderTarget & target , sf::RenderStates states ) const ;

        sf::Sprite sprite ;

        unsigned int health ;
        unsigned int maximumHealth ;
} ;
