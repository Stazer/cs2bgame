//
//  DynamicEntity.cpp
//  cs2bgame
//
//  Created by Brendan Murray on 3/2/15.
//
//

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





