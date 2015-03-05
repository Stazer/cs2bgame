#include "Interface.hpp"

Interface::Interface (Game & game, const sf::View & defaultView):
	game(game),
	camera(defaultView)
{

}

const sf::View& Interface::getCamera()const
{
    return this->camera;
}

      /*  */
void Interface::handle ( const sf::Event & event )
{
}
      /*  */
void Interface::update ( const sf::Time & frameTime )
{
    offset = sf::Vector2f ( ) ;

    if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::S ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Down ) )
        offset.y = 1 ;
    else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::W ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Up )  )
        offset.y = -1 ;

    if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::D ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Right ) )
        offset.x = 1 ;
    else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::A ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Left ) )
        offset.x = -1 ;

    offset.x *= frameTime.asMilliseconds ( ) ;
    offset.y *= frameTime.asMilliseconds ( ) ;
}
      /*  */
void Interface::draw ( sf::RenderTarget & target )
{
    sf::View view = target.getView ( ) ;
    view.move ( this->offset ) ;
    target.setView ( view ) ;
    this->camera = view ;
}
