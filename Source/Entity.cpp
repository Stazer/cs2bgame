#include "Entity.hpp"

<<<<<<< HEAD
Entity::Entity ( Map & map ) : map(map){ }


Entity::Entity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ) : map(map) , sprite(texture)
{
   setPosition(position);
}

void Entity::setTexture ( const sf::Texture & texture )
=======

Entity::Entity(Map & map){}
Entity::Entity(Map & map, const sf::Vector2f & position, const sf::Texture & texture){}


void Entity::setTexture(const sf::Texture & texture)
>>>>>>> origin/master
{
   this->sprite.setTexture(texture);
}

<<<<<<< HEAD
const sf::Texture * const Entity::getTexture ( ) const
=======
const sf::Texture * const Entity::getTexture() const
>>>>>>> origin/master
{
   return this->sprite.getTexture();
}

<<<<<<< HEAD
void Entity::setPosition ( const sf::Vector2f & position )
{
   this->sprite.setPosition(position);
}
const sf::Vector2f & Entity::getPosition ( ) const
=======
void Entity::setPosition(const sf::Vector2f & position)
{
   this->sprite.setPosition(position);
}

const sf::Vector2f & Entity::getPosition() const
>>>>>>> origin/master
{
   return this->sprite.getPosition();
}

<<<<<<< HEAD
/* set the absolute rotation of the entity, float is an measured in angle degrees */
void Entity::setRotation (float rotation)
=======
/* set the absolute rotation of the entity */
void Entity::setRotation(float rotation)
>>>>>>> origin/master
{
   this->sprite.setRotation(rotation);
}
/* retrieve the absolute rotation of the entity */
<<<<<<< HEAD
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
=======
float Entity::getRotation() const
{
   return this->sprite.getRotation();
}

Map & Entity::getMap()
{
   return map;
}
const Map & Entity::getMap() const
{
   return map;
}

void Entity::move(const sf::Vector2f & offset){}

/* rotates the orientation of the entity by offset, using the rotate method, this
rotation is relative to the entity's current orientation */
void Entity::rotate(float offset){}


/* the draw method of the target is called and sprite is one of its arguments
renderTexture.draw(sprite); // or any other drawable */
void Entity::draw(sf::RenderTarget & target) const{}

>>>>>>> origin/master
