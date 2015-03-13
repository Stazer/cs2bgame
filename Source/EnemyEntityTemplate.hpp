#pragma once

#include <string>
#include <istream>
#include <SFML/System.hpp>

class EnemyEntity ;
class Map ;

/*  */
class EnemyEntityTemplate
{
	public :
		EnemyEntityTemplate ( ) = default ;
		EnemyEntityTemplate ( const std::string & textureName , unsigned int maximumHealth , unsigned int attackPoints , unsigned int speedPoints , float detectionDistance ) ;

		void setTextureName ( const std::string & textureName ) ;
		const std::string & getTextureName ( ) const ;

		void setMaximumHealth ( unsigned int maximumHealth ) ;
		unsigned int getMaximumHealth ( ) const ;

		void setAttackPoints ( unsigned int attackPoints ) ;
		unsigned int getAttackPoints ( ) const ;

		void setSpeedPoints ( unsigned int speedPoints ) ;
		unsigned int getSpeedPoints ( ) const ;

        void setDetectionDistance ( float detectionDistance ) ;
        float getDetectionDistance ( ) const ;

        /*  */
        EnemyEntity * createEnemyEntity ( Map & map , const sf::Vector2f & position ) const ;

        void parse ( std::istream & stream ) ;

	private :
		std::string textureName ;

		unsigned int maximumHealth = 0 ;
		unsigned int attackPoints = 0 ;
		unsigned int speedPoints = 0 ;

		float detectionDistance = 0 ;
} ;
