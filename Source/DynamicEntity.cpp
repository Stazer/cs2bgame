#include "DynamicEntity.hpp"

DynamicEntity::DynamicEntity ( Map & map ) :
    Entity ( map )
{
}
DynamicEntity::DynamicEntity ( Map & map , const sf::Vector2f & position ,
                               const sf::Texture & texture , unsigned int healthPoints ,
                               unsigned int maximumHealth, unsigned int attackPoints, unsigned int speedPoints ) :
    Entity ( map , position , texture ) ,
    health ( healthPoints ) ,
    maximumHealth ( maximumHealth ) ,
    attackPoints ( attackPoints ) ,
    speedPoints ( speedPoints )
{
}


void DynamicEntity::setMaximumHealth ( unsigned int maximumHealth )
{
    this->maximumHealth = maximumHealth;
}
unsigned int DynamicEntity::getMaximumHealth ( ) const
{
    return this->maximumHealth;
}

void DynamicEntity::setHealth ( unsigned int health )
{
    if ( health > this->maximumHealth )
        this->health = this->maximumHealth ;
    else
        this->health = health;
}

unsigned int DynamicEntity::getHealth ( ) const
{
    return this->health;
}

void DynamicEntity::decreaseHealth ( unsigned int health )
{
    if ( static_cast <unsigned long> ( this->health ) - health < 0 )
        this->health = 0 ;
    else
        this->health -= health;
}

void DynamicEntity::increaseHealth ( unsigned int health )
{
    this->setHealth( this->health += health ) ;
}

void DynamicEntity::setAttackPoints ( unsigned int attackPoints )
{
    this->attackPoints = attackPoints;
}

unsigned int DynamicEntity::getAttackPoints ( ) const
{
   return  this->attackPoints;
}

void DynamicEntity::setSpeedPoints ( unsigned int speedPoints )
{
   this->speedPoints = speedPoints;
}

unsigned int DynamicEntity::getSpeedPoints ( ) const
{
   return this->speedPoints;
}

/* sets the offset y to -(speedPoints), so that the entity will move up the screen */
void DynamicEntity::moveUp ( )
{
    this->offset.y = this->getSpeedPoints ( ) * -0.01f ;
}

/* sets the offset y to +(speedPoints), so that the entity will move down the screen */
void DynamicEntity::moveDown ( )
{
    this->offset.y = this->getSpeedPoints ( ) * 0.01f ;
}

/* sets the offset x to -(speedPoints), so that the entity will move left on the screen */
void DynamicEntity::moveLeft ( )
{
    this->offset.x = this->getSpeedPoints ( ) * -0.01f ;
}

/* sets the offset x to +(speedPoints), so that the entity will move right on the screen */
void DynamicEntity::moveRight ( )
{
    this->offset.x = this->getSpeedPoints ( ) * 0.01f ;
}

/* will call the move method of the classs; the frameTime parameter is
 multiplied by the offset (measured in pixels) and updates the
 player position */
void DynamicEntity::update ( const sf::Time & frameTime )
{
    this->offset.x *= frameTime.asMilliseconds ( ) ;
    this->offset.y *= frameTime.asMilliseconds ( ) ;

    this->move ( this->offset ) ;

    this->offset = sf::Vector2f ( ) ;
}

void DynamicEntity::attack ( DynamicEntity & entity )
{
    entity.decreaseHealth ( this->getAttackPoints ( ) ) ;
}