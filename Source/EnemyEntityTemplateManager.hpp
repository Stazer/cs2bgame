#pragma once

#include <string>
#include <vector>
#include "EnemyEntityTemplate.hpp"

/*  */
class EnemyEntityTemplateManager
{
	public :
      /* */
		void readFile ( const std::string & fileName ) ;

      /*  */
		EnemyEntity * CreateRandomEnemyEntity ( const sf::Vector2f & position, float rotation ) const ;
	
	private :
		std::vector <EnemyEntityTemplate> enemyEntityTemplates ;
} ;
