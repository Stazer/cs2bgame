#include "Player.hpp"

Player::Player ( Map & map ) : DynamicEntity(map) {  }

Player::Player ( Map & map , const sf::Vector2f & position , const sf::Texture & texture ,
                 unsigned int healthPoints , unsigned int maximumHealth, unsigned int attackPoints,
                 unsigned int speedPoints, sf::Vector2f offset ) :
                 DynamicEntity(map, position, texture, healthPoints, maximumHealth, attackPoints, speedPoints),
                 offset(offset) {  }

/* sets the offset y to -(speedPoints), so that the entity will move up the screen */
void Player::moveUp ( )
{
   
}

/* sets the offset y to +(speedPoints), so that the entity will move down the screen */
void Player::moveDown ( )
{

}

/* sets the offset x to -(speedPoints), so that the entity will move left on the screen */
void Player::moveLeft ( )
{

}

/* sets the offset x to +(speedPoints), so that the entity will move right on the screen */
void Player::moveRight ( )
{

}

/* will call the move method of the classs; the frameTime parameter is
 multiplied by the offset (measured in pixels) and updates the
 player position */
void Player::update ( const sf::Time & frameTime )
{
   
}