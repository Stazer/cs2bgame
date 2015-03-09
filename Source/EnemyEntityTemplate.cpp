//
//  EnemyEntityTemplate.cpp
//  cs2bgame
//
//  Created by Brendan Murray on 3/2/15.
//
//

#include <stdio.h>
#include <string>
#include "EnemyEntityTemplate.hpp"

void EnemyEntityTemplate::setTextureName(const std::string & textureName){
    this->textureName = textureName;
}

const std::string & EnemyEntityTemplate::getTextureName() const{
    return textureName;
}

void EnemyEntityTemplate::setMaximumHealth(unsigned int maximumHealth){
    this->maximumHealth = maximumHealth;
}

unsigned int EnemyEntityTemplate::getMaximumHealth() const{
    return maximumHealth;
}

void EnemyEntityTemplate::setAttackPoints(unsigned int attackPoints){
    this->attackPoints = attackPoints;
}

unsigned int EnemyEntityTemplate::getAttackPoints() const{
    return attackPoints;
}

void EnemyEntityTemplate::setSpeedPoints(float speedPoints){
    this->speedPoints = speedPoints;
}

float EnemyEntityTemplate::getSpeedPoints() const{
    return speedPoints;
}



