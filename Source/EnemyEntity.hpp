#pragma once

#include "DynamicEntity.hpp"

class EnemyEntity : public DynamicEntity
{
	public :
		EnemyEntity ( Map & map ) ;
		EnemyEntity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture , unsigned int healthPoints , unsigned int maximumHealth , float detectionDistance ) ;
		
		void setDetectionDistance ( float detectionDistance ) ;
		float getDetectionDistance ( ) const ;
	
		virtual void update ( const sf::Time & frameTime ) ;
		virtual void draw ( sf::RenderTarget & target ) const ;
	
	private :
		DynamicEntity * targetEntity ;
		
		sf::RectangleShape healthBar ;
} ;
