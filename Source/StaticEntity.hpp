#pragma once

#include "Entity.hpp"

class StaticEntity : Entity
{
   public:
      virtual ~StaticEntity() = default;
      /*  */
      virtual void update ( const sf::Time & frameTime );
};

