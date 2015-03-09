//
//  EnemyEntity.cpp
//  cs2bgame
//
//  Created by Brendan Murray on 3/2/15.
//
//

#include <iostream>

#include "EnemyEntity.hpp"

EnemyEntity::EnemyEntity ( Map & map ) : DynamicEntity(map) { }

EnemyEntity::EnemyEntity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ,
                          unsigned int healthPoints , unsigned int maximumHealth , unsigned int attackPoints,
                          unsigned int speedPoints, float detectionDistance ) :
                         DynamicEntity(map, position, texture, healthPoints, maximumHealth, attackPoints, speedPoints),
                         detectionDistance(detectionDistance) {  }

/* this is a distance in pixels in which the artifical intelligence of the enemies
 recognizes the player and attacks them */
void EnemyEntity::setDetectionDistance ( float detectionDistance )
{
   this->detectionDistance = detectionDistance;
}

float EnemyEntity::getDetectionDistance ( ) const
{
   return this->detectionDistance;
}

/*  */
void EnemyEntity::update ( const sf::Time & frameTime )
{
   
}

/*  */
void EnemyEntity::draw ( sf::RenderTarget & target ) const
{

}


