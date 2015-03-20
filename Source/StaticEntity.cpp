#include "StaticEntity.hpp"

StaticEntity::StaticEntity ( Map & map ) :
	Entity ( map )
{
}
StaticEntity::StaticEntity ( Map & map , const sf::Vector2f & position ,  const sf::Texture & texture ) :
	Entity ( map , position , texture )
{

}

void StaticEntity::update ( const sf::Time & frameTime )
{
}