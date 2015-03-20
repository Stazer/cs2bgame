#include "EnemyEntity.hpp"
#include "Player.hpp"
#include "Map.hpp"

EnemyEntity::EnemyEntity ( Map & map ) :
    DynamicEntity ( map ) ,
    detectionDistance ( 0 )
{
}

EnemyEntity::EnemyEntity ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ,
                           unsigned int healthPoints , unsigned int maximumHealth , unsigned int attackPoints,
                           unsigned int speedPoints, float detectionDistance ) :
    DynamicEntity ( map , position , texture , healthPoints , maximumHealth , attackPoints , speedPoints ) ,
    detectionDistance ( detectionDistance )
{
}

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
    // dont update enemy logic when enemy is dead
    if ( this->isDead ( ) )
        return ;

    DynamicEntity::update ( frameTime ) ;

    // update healthbar
    this->healthBar.setFillColor ( sf::Color::Red ) ;
    this->healthBar.setOutlineColor ( sf::Color::Black ) ;
    this->healthBar.setOutlineThickness ( 1 ) ;
    this->healthBar.setSize ( sf::Vector2f ( this->getLocalBounds ( ).width * 1.5f * this->getHealth ( ) / this->getMaximumHealth ( ) , 5 ) ) ;
    this->healthBar.setOrigin ( this->healthBar.getSize ( ) * 0.5f ) ;
    this->healthBar.setPosition ( this->getPosition ( ).x , this->getPosition ( ).y - this->getLocalBounds ( ).height ) ;

    // get the difference between enemys position and players position; used for collision
    float dX = this->getPosition ( ).x - this->getMap ( ).getPlayer ( ).getPosition ( ).x ;
    float dY = this->getPosition ( ).y - this->getMap ( ).getPlayer ( ).getPosition ( ).y ;

    // if no target(player) is set then check if the player is inside the detection distance
    if ( ! this->targetEntity )
    {
        const float radiusSum = this->getDetectionDistance ( ) + this->getMap ( ).getPlayer ( ).getRadius ( ) ;

        if ( dX * dX + dY * dY <= radiusSum * radiusSum )
            this->targetEntity = & this->getMap ( ).getPlayer ( ) ;
    }
    else
    {
        // check if we are in attackrange
        if ( ! this->inRange ( * this->targetEntity ) )
        {
            // move towards the target
            dX = static_cast <int> ( dX ) ;
            dY = static_cast <int> ( dY ) ;

            if ( dX > 0 )
                this->moveLeft ( ) ;
            if ( dX < 0 )
                this->moveRight ( ) ;

            if ( dY > 0 )
                this->moveUp ( ) ;
            if ( dY < 0 )
                this->moveDown ( ) ;
        }
        // attack the target every second
        else if ( this->attackTimer.getElapsedTime ( ).asSeconds ( ) >= 1.0f )
        {
            this->attackTimer.restart ( ) ;
            this->attack ( * this->targetEntity ) ;

            if ( this->targetEntity->isDead ( ) )
                this->targetEntity = nullptr ;
        }
    }
}

/*  */
void EnemyEntity::draw ( sf::RenderTarget & target ) const
{
    DynamicEntity::draw ( target ) ;

    target.draw ( this->healthBar ) ;
}