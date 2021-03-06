#include "Entity.hpp"

Entity::Entity ( Map & map ) :
    map ( map )
{
}

Entity::Entity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ) :
    map ( map )
{
    this->setTexture ( texture ) ;
    this->setPosition ( position ) ;
}

void Entity::setTexture ( const sf::Texture & texture )
{
   this->sprite.setTexture ( texture ) ;
   this->sprite.setOrigin ( sf::Vector2f ( this->getLocalBounds ( ).width / 2.0f , this->getLocalBounds ( ).height / 2.0f ) ) ;
}
const sf::Texture * const Entity::getTexture ( ) const
{
   return this->sprite.getTexture ( ) ;
}

void Entity::setTextureRect ( const sf::IntRect & rectangle )
{
    this->sprite.setTextureRect ( rectangle ) ;
    this->sprite.setOrigin ( sf::Vector2f ( this->getLocalBounds ( ).width / 2.0f , this->getLocalBounds ( ).height / 2.0f ) ) ;
}
const sf::IntRect & Entity::getTextureRect ( ) const
{
    return this->sprite.getTextureRect ( ) ;
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

bool Entity::inRange ( const Entity & entity ) const
{
    const float dX = this->getPosition ( ).x - entity.getPosition ( ).x ;
    const float dY = this->getPosition ( ).y - entity.getPosition ( ).y ;

    const float radiusSum = this->getRadius ( ) * 2.0f + entity.getRadius ( ) * 2.0f ;

    return ( dX * dX + dY * dY <= radiusSum * radiusSum ) ;
}

/* the draw method of the target is called and sprite is one of its arguments
 renderTexture.draw(sprite); // or any other drawable */
void Entity::draw ( sf::RenderTarget & target ) const
{
    target.draw ( this->sprite ) ;
}