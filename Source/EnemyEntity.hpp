/* for help look at:
 http://www.sfml-dev.org/tutorials/2.2/
 */

#pragma once

#include "DynamicEntity.hpp"

class EnemyEntity : public DynamicEntity
{
	public :
		EnemyEntity ( Map & map ) ;
		EnemyEntity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ,
                   unsigned int healthPoints , unsigned int maximumHealth, unsigned int attackPoints,
                   unsigned int speedPoints, float detectionDistance ) ;
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
		float detectionDistance = 0 ;

        /* this member will always be set to the player entity because we want the enemies
        to only attack the player and not eachother */
		DynamicEntity * targetEntity = nullptr ;

        /* this is a small sprite which will visually display the health of the enemy */
		sf::RectangleShape healthBar ;
} ;
