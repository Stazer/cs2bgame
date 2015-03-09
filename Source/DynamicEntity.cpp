//
//  DynamicEntity.cpp
//  cs2bgame
//
//  Created by Brendan Murray on 3/2/15.
//
//

/*<<<<<<< HEAD*/
#include "DynamicEntity.hpp"

DynamicEntity::DynamicEntity ( Map & map ) : Entity(map) { }

DynamicEntity::DynamicEntity ( Map & map , const sf::Vector2f & position ,
                              const sf::Texture & texture , unsigned int healthPoints ,
                              unsigned int maximumHealth, unsigned int attackPoints, unsigned int speedPoints) :
                              Entity(map), health(healthPoints), maximumHealth(maximumHealth),
                              attackPoints(attackPoints), speedPoints(speedPoints) { }


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
   this->health = health;
}

unsigned int DynamicEntity::getHealth ( ) const
{
   return this->health;
}

void DynamicEntity::decreaseHealth ( unsigned int health )
{
   this->health -= health;
}

void DynamicEntity::increaseHealth ( unsigned int health )
{
   this->health += health;
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
/*=======
#include <stdio.h>
#include "DynamicEntity.hpp"

void DynamicEntity::setMaximumHealth(unsigned int maximumHealth) {
    this->maximumHealth = maximumHealth;
}

unsigned int DynamicEntity::getMaximumHealth() const{
    return maximumHealth;
}

void DynamicEntity::setAttackPoints(unsigned int attackPoints){
    this->attackPoints = attackPoints;
}

unsigned int DynamicEntity::getAttackPoints() const{
    return attackPoints;
}

void DynamicEntity::setSpeedPoints(unsigned int speedPoints){
    this->speedPoints = speedPoints;
}

unsigned int DynamicEntity::getSpeedPoints() const{
    return speedPoints;
}





>>>>>>> origin/master*/
