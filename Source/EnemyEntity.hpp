/* for help look at:
 http://www.sfml-dev.org/tutorials/2.2/
 */

#pragma once

#include "DynamicEntity.hpp"

class EnemyEntity : public DynamicEntity
{
	public :
		EnemyEntity ( Map & map ) ;
		EnemyEntity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture , unsigned int healthPoints , unsigned int maximumHealth , float detectionDistance ) ;
      virtual ~EnemyEntity () = default;

      /* this is a distance in pixels in which the artifical intelligence of the enemies
       recognizes the player and attacks them */
		void setDetectionDistance ( float detectionDistance ) ;
		float getDetectionDistance ( ) const ;

      /*  */
		virtual void update ( const sf::Time & frameTime ) ;
      /*  */
		virtual void draw ( sf::RenderTarget & target ) const ;
	
	private :
		DynamicEntity * targetEntity ;
		sf::RectangleShape healthBar ;
} ;
