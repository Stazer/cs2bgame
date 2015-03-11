#include "Player.hpp"

Player::Player ( Map & map ) :
    DynamicEntity ( map )
{
}

Player::Player ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ,
                 unsigned int healthPoints , unsigned int maximumHealth , unsigned int attackPoints ,
                 unsigned int speedPoints ) :
    DynamicEntity ( map , position , texture , healthPoints , maximumHealth , attackPoints , speedPoints )
{
}

/* sets the offset y to -(speedPoints), so that the entity will move up the screen */
void Player::moveUp ( )
{
    this->offset.y = this->getSpeedPoints ( ) * -0.01f ;
}

/* sets the offset y to +(speedPoints), so that the entity will move down the screen */
void Player::moveDown ( )
{
    this->offset.y = this->getSpeedPoints ( ) * 0.01f ;
}

/* sets the offset x to -(speedPoints), so that the entity will move left on the screen */
void Player::moveLeft ( )
{
    this->offset.x = this->getSpeedPoints ( ) * -0.01f ;
}

/* sets the offset x to +(speedPoints), so that the entity will move right on the screen */
void Player::moveRight ( )
{
    this->offset.x = this->getSpeedPoints ( ) * 0.01f ;
}

/* will call the move method of the classs; the frameTime parameter is
 multiplied by the offset (measured in pixels) and updates the
 player position */
void Player::update ( const sf::Time & frameTime )
{
    this->offset.x *= frameTime.asMilliseconds ( ) ;
    this->offset.y *= frameTime.asMilliseconds ( ) ;

    this->move ( this->offset ) ;

    this->offset = sf::Vector2f ( ) ;
}