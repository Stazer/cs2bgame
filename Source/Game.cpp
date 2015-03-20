#include "Game.hpp"

Game::Game ( TextureManager & textureManager, AudioManager & audioManager , FontManager & fontManager , sf::RenderWindow & window ) :
	textureManager ( textureManager ) ,
	audioManager ( audioManager ) ,
	fontManager ( fontManager ) ,
	map ( * this ) ,
	player ( this->map ) ,
	interface ( * this , window )
{
    // setup instructionsprite(menu)
    this->instructions.setTexture ( textureManager.get ( "Instructions" ) ) ;
    this->instructions.setOrigin ( this->instructions.getLocalBounds ( ).width / 2.0f , this->instructions.getLocalBounds ( ).height / 2.0f ) ;
    this->instructions.setPosition ( window.getView ( ).getCenter ( ) ) ;
}

const TextureManager & Game::getTextureManager ( ) const
{
    return this->textureManager ;
}
TextureManager & Game::getTextureManager ( )
{
    return this->textureManager ;
}

const AudioManager & Game::getAudioManager ( ) const
{
    return this->audioManager ;
}
AudioManager & Game::getAudioManager ( )
{
    return this->audioManager ;
}

const FontManager & Game::getFontManager ( ) const
{
    return this->fontManager ;
}
FontManager & Game::getFontManager ( )
{
    return this->fontManager ;
}

const Map & Game::getMap ( ) const
{
    return this->map ;
}
Map & Game::getMap ( )
{
    return this->map ;
}

const Player & Game::getPlayer ( ) const
{
    return this->player ;
}
Player & Game::getPlayer ( )
{
    return this->player ;
}

const Interface& Game::getInterface ( ) const
{
    return this->interface;
}
Interface& Game::getInterface ( )
{
    return this->interface;
}

EnemyEntityTemplateManager & Game::getEnemyEntityTemplateManager ( )
{
    return this->enemyEntityTemplateManager ;
}
const EnemyEntityTemplateManager & Game::getEnemyEntityTemplateManager ( ) const
{
    return this->enemyEntityTemplateManager ;
}

void Game::setKills ( unsigned int kills )
{
    this->kills = kills ;
}
unsigned int Game::getKills ( ) const
{
    return this->kills ;
}
void Game::addKill ( )
{
    ++this->kills ;
}

const sf::Clock & Game::getTimer ( ) const
{
    return this->timer ;
}

/*  */
void Game::handle ( const sf::Event & event )
{
    if ( this->isPlaying )
    {
        this->interface.handle ( event ) ;

        if ( event.type == sf::Event::KeyPressed &&
             event.key.code == sf::Keyboard::Escape )
            this->stop ( ) ;
    }
    else
    {
        if ( event.type == sf::Event::KeyPressed )
        {
            if ( event.key.code == sf::Keyboard::Return )
                this->play ( ) ;
            else if ( event.key.code == sf::Keyboard::Escape )
                this->getInterface ( ).getWindow ( ).close ( ) ;

        }
    }
}
void Game::update ( const sf::Time & frameTime )
{
    // update the game logic if we are playing the game
    if ( this->isPlaying )
    {
        this->map.update ( frameTime ) ;
        this->player.update ( frameTime ) ;
        this->interface.update ( frameTime ) ;

        if ( this->player.isDead ( ) )
            this->stop ( ) ;
    }
}
void Game::draw ( sf::RenderTarget & target )
{
    if ( this->isPlaying )
    {
        this->map.draw ( target ) ;
        this->player.draw ( target ) ;
        this->interface.draw ( target ) ;
    }
    else
        target.draw ( this->instructions ) ;
}

void Game::play ( )
{
    // read creatures
    this->enemyEntityTemplateManager.readFile ( "Data/Creatures" ) ;

    // setup player statistics
    this->player.setMaximumHealth ( 1000 ) ;
    this->player.setHealth ( 1000 ) ;
    this->player.setTexture ( this->textureManager.get ( "Player" ) ) ;
    this->player.setPosition ( this->interface.getCamera ( ).getCenter ( ) ) ;
    this->player.setSpeedPoints ( 1000 ) ;
    this->player.setAttackPoints ( 100 ) ;

    // reset statistics
    this->kills = 0 ;
    this->timer.restart ( ) ;

    // clear the map
    this->map.clear ( ) ;

    this->isPlaying = true ;
}
void Game::stop ( )
{
    // reset the view
    this->interface.getWindow ( ).setView ( this->interface.getWindow ( ).getDefaultView ( ) ) ;

    this->isPlaying = false ;
}