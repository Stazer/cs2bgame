#pragma once

#include "Entity.hpp"

class StaticEntity : Entity
{
   public:
	   StaticEntity ( Map & map ) ;
	   StaticEntity ( Map & map , const sf::Vector2f & position ,
		              const sf::Texture & texture );

	   virtual ~StaticEntity() = default ;
		  
	   virtual void update ( const sf::Time & frameTime );
};

