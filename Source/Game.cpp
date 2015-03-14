#include "Game.hpp"

Game::Game ( TextureManager & textureManager, AudioManager & audioManager , const sf::RenderTarget & target , const std::string & creaturesFileName ) :
	textureManager ( textureManager ) ,
	audioManager ( audioManager ) ,
	map ( * this ) ,
	player ( this->map ) ,
	interface ( * this , target )
{
    this->enemyEntityTemplateManager.readFile ( creaturesFileName ) ;

    this->player.setMaximumHealth ( 1000 ) ;
    this->player.setHealth ( 1000 ) ;

    this->player.setTexture ( this->textureManager.get ( "Player" ) ) ;
    this->player.setPosition ( target.getView ( ).getCenter ( ) ) ;
    this->player.setSpeedPoints ( 1000 ) ;
    this->player.setAttackPoints ( 100 ) ;

}

const TextureManager & Game::getTextureManager ( ) const
{
    return this->textureManager ;
}
TextureManager & Game::getTextureManager ( )
{
    return this->textureManager ;
}

const AudioManager& Game::getAudioManager ( ) const
{
    return this->audioManager ;
}
AudioManager& Game::getAudioManager ( )
{
    return this->audioManager ;
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

/*  */
void Game::handle ( const sf::Event & event )
{
    this->interface.handle ( event ) ;
}
void Game::update ( const sf::Time & frameTime )
{
	this->map.update ( frameTime ) ;
	this->player.update ( frameTime ) ;
    this->interface.update ( frameTime ) ;
}
void Game::draw ( sf::RenderTarget & target )
{
	this->map.draw ( target ) ;
    this->player.draw ( target ) ;
    this->interface.draw ( target ) ;
}
