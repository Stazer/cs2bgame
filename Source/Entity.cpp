#include "Entity.hpp"

Entity::Entity ( Map & map ) : map(map){ }


Entity::Entity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ) : map(map) , sprite(texture)
{
   setPosition(position);
}

void Entity::setTexture ( const sf::Texture & texture )
{
   this->sprite.setTexture(texture);
}

const sf::Texture * const Entity::getTexture ( ) const
{
   return this->sprite.getTexture();
}

void Entity::setPosition ( const sf::Vector2f & position )
{
   this->sprite.setPosition(position);
}
const sf::Vector2f & Entity::getPosition ( ) const
{
   return this->sprite.getPosition();
}

/* set the absolute rotation of the entity, float is an measured in angle degrees */
void Entity::setRotation (float rotation)
{
   this->sprite.setRotation(rotation);
}
/* retrieve the absolute rotation of the entity */
float Entity::getRotation ( ) const
{
   this->sprite.getRotation();
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
   this->sprite.move(offset);
}

/* rotates the orientation of the entity by offset, using the rotate method, this
 rotation is relative to the entity's current orientation */
void Entity::rotate (float offset)
{
   this->sprite.rotate(offset);
}

/* the draw method of the target is called and sprite is one of its arguments
 renderTexture.draw(sprite); // or any other drawable */
void Entity::draw ( sf::RenderTarget & target ) const ;