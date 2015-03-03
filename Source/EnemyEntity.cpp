//
//  EnemyEntity.cpp
//  cs2bgame
//
//  Created by Brendan Murray on 3/2/15.
//
//

#include <iostream>

#include "EnemyEntity.hpp"

EnemyEntity::EnemyEntity ( Map & map )
{

}

EnemyEntity::EnemyEntity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ,
             unsigned int healthPoints , unsigned int maximumHealth , float detectionDistance )
{

}
EnemyEntity::~EnemyEntity () = default;

/* this is a distance in pixels in which the artifical intelligence of the enemies
 recognizes the player and attacks them */
void EnemyEntity::setDetectionDistance ( float detectionDistance ) ;
float EnemyEntity::getDetectionDistance ( ) const ;

/*  */
void EnemyEntity::update ( const sf::Time & frameTime ) ;
/*  */
void EnemyEntity::draw ( sf::RenderTarget & target ) const ;