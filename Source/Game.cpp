#include "Game.hpp"

void Game::handle ( const sf::Event & event )
{
}
void Game::update ( const sf::Time & frameTime )
{
    this->scrollOffset = sf::Vector2f ( ) ;

    if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Right ) )
        this->scrollOffset.x = 2 ;
    else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Left ) )
        this->scrollOffset.x = -2 ;

    if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Up ) )
        this->scrollOffset.y = -2 ;
    else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Down ) )
        this->scrollOffset.y = 2 ;

    this->scrollOffset.x *= frameTime.asMilliseconds ( ) ;
    this->scrollOffset.y *= frameTime.asMilliseconds ( ) ;
}
void Game::draw ( sf::RenderTarget & target )
{
    sf::View savedView ( target.getView ( ) ) ;

    if ( this->scrollOffset.x || this->scrollOffset.y )
        savedView.move ( this->scrollOffset ) ;

    target.draw ( sf::CircleShape ( 50 ) ) ;

    target.setView ( savedView ) ;
}