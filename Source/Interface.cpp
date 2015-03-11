#include "Interface.hpp"
#include "Game.hpp"

Interface::Interface ( Game & game , const sf::View & defaultView ) :
	game ( game ) ,
	camera ( defaultView ) ,
    healthBar ( sf::Vector2f ( defaultView.getSize ( ).x , 16 ) )
{
    this->healthBar.setFillColor ( sf::Color::Red ) ;
    this->healthBar.setOutlineColor ( sf::Color::Black ) ;
    this->healthBar.setOutlineThickness ( 1 ) ;
}

const sf::View & Interface::getCamera ( ) const
{
    return this->camera ;
}

/*  */
void Interface::handle ( const sf::Event & event )
{
}
/*  */
void Interface::update ( const sf::Time & frameTime )
{
    if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::S ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Down ) )
        this->game.getPlayer ( ).moveDown ( ) ;
    else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::W ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Up )  )
        this->game.getPlayer ( ).moveUp ( ) ;
    else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::D ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Right ) )
        this->game.getPlayer ( ).moveRight ( ) ;
    else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::A ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Left ) )
        this->game.getPlayer ( ).moveLeft ( ) ;

    this->healthBar.setSize ( sf::Vector2f ( this->camera.getSize ( ).x * this->game.getPlayer ( ).getHealth ( ) / this->game.getPlayer ( ).getMaximumHealth ( ) , this->healthBar.getSize ( ).y ) ) ;
}
      /*  */
void Interface::draw ( sf::RenderTarget & target )
{
    sf::View view = target.getView ( ) ;
    view.setCenter ( this->game.getPlayer ( ).getPosition ( ) ) ;
    this->camera = view ;

    target.setView( target.getDefaultView ( ) ) ;
    target.draw ( this->healthBar ) ;


    target.setView ( view ) ;
}