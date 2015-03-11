#include "Entity.hpp"

Entity::Entity ( Map & map ) : map(map){ }


Entity::Entity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ) :
    map ( map )
{
    this->setTexture ( texture ) ;
    this->setPosition ( position ) ;
}

void Entity::setTexture ( const sf::Texture & texture )
{
   this->sprite.setTexture ( texture ) ;
   this->sprite.setOrigin ( texture.getSize ( ).x / 2.0f , texture.getSize ( ).y / 2.0f ) ;
}

const sf::Texture * const Entity::getTexture ( ) const
{
   return this->sprite.getTexture ( ) ;
}

void Entity::setPosition ( const sf::Vector2f & position )
{
   this->sprite.setPosition (position ) ;
}

const sf::Vector2f & Entity::getPosition ( ) const
{
   return this->sprite.getPosition ( ) ;
}

Map & Entity::getMap ( )
{
   return this->map;
}
const Map & Entity::getMap ( ) const
{
   return this->map;
}

void Entity::move ( const sf::Vector2f & offset )
{
   this->sprite.move ( offset ) ;
}

sf::FloatRect Entity::getGlobalBounds ( ) const
{
    return this->sprite.getGlobalBounds ( ) ;
}
sf::FloatRect Entity::getLocalBounds ( ) const
{
    return this->sprite.getLocalBounds ( ) ;
}

float Entity::getRadius ( ) const
{
    return ( this->sprite.getLocalBounds ( ).width + this->sprite.getLocalBounds ( ).height ) / 4.0f ;
}

/* the draw method of the target is called and sprite is one of its arguments
 renderTexture.draw(sprite); // or any other drawable */
void Entity::draw ( sf::RenderTarget & target ) const
{
    target.draw ( this->sprite ) ;
}