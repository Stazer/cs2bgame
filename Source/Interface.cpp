#include "Interface.hpp"
#include "Game.hpp"
#include "EnemyEntity.hpp"

Interface::Interface ( Game & game , const sf::RenderTarget & target ) :
	game ( game ) ,
	target ( target ) ,
    healthBar ( sf::Vector2f ( target.getView ( ).getSize ( ).x , 16 ) )
{
    this->healthBar.setFillColor ( sf::Color::Red ) ;
    this->healthBar.setOutlineColor ( sf::Color::Black ) ;
    this->healthBar.setOutlineThickness ( 1 ) ;
}

const sf::View & Interface::getCamera ( ) const
{
    return this->target.getView ( ) ;
}
const sf::RenderTarget & Interface::getTarget ( ) const
{
    return this->target ;
}

/*  */
void Interface::handle ( const sf::Event & event )
{
    if ( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left )
    {
        for ( auto iterator = this->game.getMap ( ).getEntities ( ).begin ( ) ; iterator != this->game.getMap ( ).getEntities ( ).end ( ) ; ++iterator )
        {
            EnemyEntity * enemy = dynamic_cast <EnemyEntity *> ( iterator->get ( ) ) ;

            if ( enemy && enemy->getGlobalBounds ( ).contains ( this->target.mapPixelToCoords ( sf::Vector2i ( event.mouseButton.x , event.mouseButton.y ) ) ) && this->game.getPlayer ( ).inRange ( * enemy ) )
            {
                this->game.getPlayer ( ).attack ( * enemy ) ;
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

    this->healthBar.setSize ( sf::Vector2f ( this->getCamera ( ).getSize ( ).x * this->game.getPlayer ( ).getHealth ( ) / this->game.getPlayer ( ).getMaximumHealth ( ) , this->healthBar.getSize ( ).y ) ) ;
}
      /*  */
void Interface::draw ( sf::RenderTarget & target )
{
    sf::View view = target.getView ( ) ;
    view.setCenter ( this->game.getPlayer ( ).getPosition ( ) ) ;

    target.setView ( target.getDefaultView ( ) ) ;
    target.draw ( this->healthBar ) ;

    target.setView ( view ) ;
}