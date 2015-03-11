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