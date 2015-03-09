#include "StaticEntity.hpp"

StaticEntity::StaticEntity ( Map & map ) :
	Entity ( map )
{
}
StaticEntity::StaticEntity ( Map & map , const sf::Vector2f & position ,  const sf::Texture & texture ) :
	Entity ( map , position , texture )
=======
#include <stdio.h>

StaticEntity::StaticEntity ( Map & map ) : Entity (map) { }

StaticEntity::StaticEntity ( Map & map , const sf::Vector2f & position ,
                            const sf::Texture & texture ) : Entity(map)
>>>>>>> 2de92c7999cc4e7c03d27524e240a8c84a157cf1
{

}

void StaticEntity::update ( const sf::Time & frameTime )
{

}
