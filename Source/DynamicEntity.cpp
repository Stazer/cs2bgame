#include "DynamicEntity.hpp"
#include "Game.hpp"
#include "AudioManager.hpp"

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
    if ( ( static_cast <long> ( this->health ) - health ) < 0 )
        this->health = 0 ;
    else
        this->health -= health ;
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
    this->offset.y = - 1 ;
}

/* sets the offset y to +(speedPoints), so that the entity will move down the screen */
void DynamicEntity::moveDown ( )
{
    this->offset.y = 1 ;
}

/* sets the offset x to -(speedPoints), so that the entity will move left on the screen */
void DynamicEntity::moveLeft ( )
{
    this->offset.x = - 1 ;
}

/* sets the offset x to +(speedPoints), so that the entity will move right on the screen */
void DynamicEntity::moveRight ( )
{
    this->offset.x = 1 ;
}

bool DynamicEntity::isDead ( ) const
{
    return ( this->getHealth ( ) == 0 ) ;
}
bool DynamicEntity::isAlive ( ) const
{
    return ! this->isDead ( ) ;
}

/* will call the move method of the classs; the frameTime parameter is
 multiplied by the offset (measured in pixels) and updates the
 player position */
void DynamicEntity::update ( const sf::Time & frameTime )
{
    // handle the first part of the animated sprite
    if ( ! this->animationStep )
    {
        const sf::Texture * const texture = this->getTexture ( ) ;

        if ( texture  )
        {
            this->setTextureRect ( sf::IntRect ( texture->getSize ( ).x / 2.0f , 0 , texture->getSize ( ).x / 2.0f , texture->getSize ( ).y )  ) ;
        }

        ++this->animationStep ;
    }

    // handle rotation of sprite
    if ( this->offset.x == -1 )
        if ( this->offset.y == 1 )
            this->sprite.setRotation ( 135 ) ;
        else if ( this->offset.y == -1 )
            this->sprite.setRotation ( -135 ) ;
        else
            this->sprite.setRotation ( 180 ) ;
    else if ( this->offset.x == 1 )
        if ( this->offset.y == 1 )
            this->sprite.setRotation ( 45 ) ;
        else if ( this->offset.y == -1 )
            this->sprite.setRotation ( -45 ) ;
        else
            this->sprite.setRotation ( 0 ) ;
    else if ( this->offset.y == 1 )
            this->sprite.setRotation ( 90 ) ;
    else if ( this->offset.y == -1 )
            this->sprite.setRotation ( -90 ) ;

    // handle sprite movement
    this->offset.x *= frameTime.asSeconds ( ) * this->getSpeedPoints ( ) ;
    this->offset.y *= frameTime.asSeconds ( ) * this->getSpeedPoints ( )  ;

    // handle animation of movement
    const sf::Texture * const texture = this->getTexture ( ) ;
    if ( texture && ( offset.x || offset.y ) )
    {
        if ( this->animationTimer.getElapsedTime ( ).asSeconds ( )  * this->getSpeedPoints ( ) * 0.001f > frameTime.asSeconds ( ) )
        {
            this->setTextureRect ( sf::IntRect ( ( this->animationStep - 1 ) * texture->getSize ( ).x / 2.0f , 0 , texture->getSize ( ).x / 2.0f , texture->getSize ( ).y )  ) ;

            // use the ?-operator for if-else statement
            this->animationStep = ( this->animationStep == 1 ) ? 2 : 1 ;

            this->animationTimer.restart ( ) ;
        }
    }

    // move the sprite and reset the offset vector
    this->move ( this->offset ) ;
    this->offset = sf::Vector2f ( ) ;
}

void DynamicEntity::attack ( DynamicEntity & entity )
{
    entity.decreaseHealth ( this->getAttackPoints ( ) ) ;

    this->getMap ( ).getGame ( ).getAudioManager ( ).getSound ( "Hit" ).play ( ) ;
}