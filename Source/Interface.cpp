#include "Interface.hpp"
#include "Game.hpp"
#include "EnemyEntity.hpp"
#include <sstream>

Interface::Interface ( Game & game , sf::RenderWindow & window ) :
	game ( game ) ,
	window ( window ) ,
    healthBar ( sf::Vector2f ( window.getView ( ).getSize ( ).x , 16 ) )
{
    this->healthBar.setFillColor ( sf::Color::Red ) ;
    this->healthBar.setOutlineColor ( sf::Color::Black ) ;
    this->healthBar.setOutlineThickness ( 1 ) ;

    this->statistics.setFont ( this->game.getFontManager ( ).get ( "Arial" ) ) ;
    this->statistics.setCharacterSize ( 30 ) ;
}

const sf::View & Interface::getCamera ( ) const
{
    return this->window.getView ( ) ;
}
sf::RenderWindow & Interface::getWindow ( )
{
    return this->window ;
}
const sf::RenderWindow & Interface::getWindow ( ) const
{
    return this->window ;
}

/*  */
void Interface::handle ( const sf::Event & event )
{
    if ( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left )
    {
        for ( auto iterator = this->game.getMap ( ).getEntities ( ).begin ( ) ; iterator != this->game.getMap ( ).getEntities ( ).end ( ) ; ++iterator )
        {
            EnemyEntity * enemy = dynamic_cast <EnemyEntity *> ( iterator->get ( ) ) ;

            if ( enemy && enemy->getGlobalBounds ( ).contains ( this->window.mapPixelToCoords ( sf::Vector2i ( event.mouseButton.x , event.mouseButton.y ) ) ) && this->game.getPlayer ( ).inRange ( * enemy ) )
            {
                this->game.getPlayer ( ).attack ( * enemy ) ;

                if ( enemy->isDead ( ) )
                    this->game.addKill ( ) ;

                break ;
            }
        }
    }
}

/*  */
void Interface::update ( const sf::Time & frameTime )
{
    if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::S ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Down ) )
        this->game.getPlayer ( ).moveDown ( ) ;
    if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::W ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Up )  )
        this->game.getPlayer ( ).moveUp ( ) ;
    if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::D ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Right ) )
        this->game.getPlayer ( ).moveRight ( ) ;
    if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::A ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Left ) )
        this->game.getPlayer ( ).moveLeft ( ) ;

    std::stringstream buffer ;
    buffer << this->game.getKills ( ) << " kills - " << this->game.getTimer ( ).getElapsedTime ( ).asSeconds ( ) ;
    this->statistics.setString ( buffer.str ( ) ) ;

    this->statistics.setPosition ( 40 , 40 ) ;

    this->healthBar.setSize ( sf::Vector2f ( this->getCamera ( ).getSize ( ).x * this->game.getPlayer ( ).getHealth ( ) / this->game.getPlayer ( ).getMaximumHealth ( ) , this->healthBar.getSize ( ).y ) ) ;
}
      /*  */
void Interface::draw ( sf::RenderTarget & target )
{
    sf::View view = target.getView ( ) ;
    view.setCenter ( this->game.getPlayer ( ).getPosition ( ) ) ;

    target.setView ( target.getDefaultView ( ) ) ;
    target.draw ( this->healthBar ) ;
    target.draw ( this->statistics ) ;

    target.setView ( view ) ;
}