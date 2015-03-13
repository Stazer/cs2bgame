#include <string>
#include "EnemyEntityTemplate.hpp"
#include "EnemyEntity.hpp"
#include "Game.hpp"
#include "Map.hpp"

EnemyEntityTemplate::EnemyEntityTemplate ( const std::string & textureName , unsigned int maximumHealth , unsigned int attackPoints , unsigned int speedPoints , float detectionDistance ) :
    textureName ( textureName ) ,
    maximumHealth ( maximumHealth ) ,
    attackPoints ( attackPoints ) ,
    speedPoints ( speedPoints ) ,
    detectionDistance ( detectionDistance )
{
}

void EnemyEntityTemplate::setTextureName ( const std::string & textureName )
{
    this->textureName = textureName ;
}
const std::string & EnemyEntityTemplate::getTextureName ( ) const
{
    return textureName ;
}

void EnemyEntityTemplate::setMaximumHealth ( unsigned int maximumHealth )
{
    this->maximumHealth = maximumHealth ;
}
unsigned int EnemyEntityTemplate::getMaximumHealth ( ) const
{
    return maximumHealth ;
}

void EnemyEntityTemplate::setAttackPoints ( unsigned int attackPoints )
{
    this->attackPoints = attackPoints ;
}
unsigned int EnemyEntityTemplate::getAttackPoints ( ) const
{
    return attackPoints ;
}

void EnemyEntityTemplate::setSpeedPoints ( unsigned int speedPoints )
{
    this->speedPoints = speedPoints ;
}
unsigned int EnemyEntityTemplate::getSpeedPoints ( ) const
{
    return speedPoints ;
}

void EnemyEntityTemplate::setDetectionDistance ( float detectionDistance )
{
    this->detectionDistance = detectionDistance ;
}
float EnemyEntityTemplate::getDetectionDistance ( ) const
{
    return this->detectionDistance ;
}

/*  */
EnemyEntity * EnemyEntityTemplate::createEnemyEntity ( Map & map , const sf::Vector2f & position ) const
{
    return new EnemyEntity ( map , position , map.getGame ( ).getTextureManager ( ).get ( this->textureName ) , this->maximumHealth , this->maximumHealth , this->attackPoints , this->speedPoints , this->detectionDistance ) ;
}

void EnemyEntityTemplate::parse ( std::istream & stream )
{
    std::getline ( stream , this->textureName , ';' ) ;

    std::string buffer ;

    std::getline ( stream , buffer , ';' ) ;
    this->maximumHealth = atoi ( buffer.c_str ( ) ) ;

    std::getline ( stream , buffer , ';' ) ;
    this->attackPoints = atoi ( buffer.c_str ( ) ) ;

    std::getline ( stream , buffer , ';' ) ;
    this->speedPoints = atoi ( buffer.c_str ( ) ) ;

    std::getline ( stream , buffer , ';' ) ;
    this->detectionDistance = atof ( buffer.c_str ( ) ) ;
}