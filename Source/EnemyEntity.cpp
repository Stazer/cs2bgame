#include "EnemyEntity.hpp"
#include "Player.hpp"
#include "Map.hpp"

EnemyEntity::EnemyEntity ( Map & map ) :
    DynamicEntity ( map ) ,
    detectionDistance ( 0 )
{
    this->healthBar.setFillColor ( sf::Color::Red ) ;
    this->healthBar.setOutlineColor ( sf::Color::Black ) ;
    this->healthBar.setOutlineThickness ( 1 ) ;
    this->healthBar.setSize ( sf::Vector2f ( 100 , 5 ) ) ;
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
    DynamicEntity::update ( frameTime ) ;
    this->healthBar.setSize ( sf::Vector2f ( this->getLocalBounds ( ).width * 1.5f * this->getHealth ( ) / this->getMaximumHealth ( ) , this->healthBar.getSize ( ).y ) ) ;
    this->healthBar.setOrigin ( this->healthBar.getSize ( ) * 0.5f ) ;
    this->healthBar.setPosition ( this->getPosition ( ).x , this->getPosition ( ).y - this->getLocalBounds ( ).height ) ;

    float dX = this->getPosition ( ).x - this->getMap ( ).getPlayer ( ).getPosition ( ).x ;
    float dY = this->getPosition ( ).y - this->getMap ( ).getPlayer ( ).getPosition ( ).y ;

    if ( ! this->targetEntity )
    {
        const float radiusSum = this->getDetectionDistance ( ) + this->getMap ( ).getPlayer ( ).getRadius ( ) ;

        if ( dX * dX + dY * dY <= radiusSum * radiusSum )
            this->targetEntity = & this->getMap ( ).getPlayer ( ) ;
    }
    else
    {
        /*const float radiusSum = 1.5f * ( this->getRadius ( ) + this->getMap ( ).getPlayer ( ).getRadius ( ) ) ;

        if ( dX * dX + dY * dY <= radiusSum * radiusSum )
        {
            dX = 0 ;
            dY = 0 ;
        }



        if ( dX > 0 )
            this->moveLeft ( ) ;
        else if ( dX < 0 )
            this->moveRight ( ) ;

        else if ( dY > 0 )
            this->moveUp ( ) ;
        else if ( dY < 0 )
            this->moveDown ( ) ;*/
    }
}

/*  */
void EnemyEntity::draw ( sf::RenderTarget & target ) const
{
    DynamicEntity::draw ( target ) ;
    target.draw ( this->healthBar ) ;

    sf::CircleShape circle ;

    circle.setOutlineColor ( sf::Color ( 255 , 0 , 0 , 100 ) ) ;
    circle.setOutlineThickness ( 1 ) ;
    circle.setFillColor(sf::Color ( 0 , 0 , 0 , 0 ) ) ;
    circle.setRadius(this->getDetectionDistance());
    circle.setOrigin(sf::Vector2f (circle.getLocalBounds().width / 2.0f , circle.getLocalBounds().height / 2.0f ));
    circle.setPosition ( this->getPosition());

    target.draw ( circle ) ;
}