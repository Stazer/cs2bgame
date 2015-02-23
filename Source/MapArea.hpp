#pragma once

class MapArea
{
	public :
		enum Type
		{
			Snow ,
			Grass ,
			Dirt
		} ;
		
		MapArea ( Type type , const sf::Vector2f & position , const sf::Vector2f & size ) ;
		
		Type getType ( ) const ;
		const sf::Vector2f & getPosition ( ) const ;
		const sf::Vector2f & getSize ( ) const ;
		
		void draw ( sf::RenderTarget & target ) const ;
	
	private :
		Type type ;
	
		sf::Vector2f position ;
		sf::Vector2f size ;
	
		std::vector <sf::Sprite> tiles ;
} ;
