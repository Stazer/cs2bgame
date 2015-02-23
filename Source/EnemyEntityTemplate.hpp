#pragma once

#include <string>
#include "EnemyEntity.hpp"

class EnemyEntityTemplate
{
	public :
		EnemyEntityTemplate ( ) = default ;
		EnemyEntityTemplate ( const std::string & textureName , unsigned int maximumHealth , unsigned int attackPoints , float speedPoints ) ;
		
		void setTextureName ( const std::string & textureName ) ;
		const std::string & getTextureName ( ) const ;
		
		void setMaximumHealth ( unsigned int maximumHealth ) ;
		unsigned int getMaximumHealth ( ) const ;
		
		void setAttackPoints ( unsigned int attackPoints ) ;
		unsigned int getAttackPoints ( ) const ;
		
		void setSpeedPoints ( float speedPoints ) ;
		float getSpeedPoints ( ) const ;

		EnemyEntity * CreateEnemyEntity ( ) const ;
	
	private :
		std::string textureName ;
		
		unsigned int maximumHealth ;
		unsigned int attackPoints ;
		unsigned int speedPoints ;
} ;
