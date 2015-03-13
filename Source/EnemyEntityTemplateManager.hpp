#pragma once

#include <string>
#include <vector>
#include "EnemyEntityTemplate.hpp"

class Map ;
/*  */
class EnemyEntityTemplateManager
{
	public :
      /* */
		void readFile ( const std::string & fileName ) ;

      /*  */
		EnemyEntity * createRandomEnemyEntity ( Map & map , const sf::Vector2f & position ) const ;

	private :
		std::vector <EnemyEntityTemplate> enemyEntityTemplates ;
} ;
