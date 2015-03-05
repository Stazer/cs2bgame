#include "Game.hpp"

Game::Game (TextureManager& textureManager, AudioManager& audioManager, const sf::View & defaultView):
	textureManager(textureManager),
	audioManager(audioManager),
	map(*this),
	interface(*this, defaultView)
{
}

const TextureManager& Game::getTextureManager()const
{
    return this->textureManager ;
}
TextureManager& Game::getTextureManager()
{
    return this->textureManager ;
}

const AudioManager& Game::getAudioManager()const
{
    return this->audioManager ;
}
AudioManager& Game::getAudioManager()
{
    return this->audioManager ;
}

const Interface& Game::getInterface() const
{
    return this->interface;
}
Interface& Game::getInterface()
{
    return this->interface;
}

/*  */
void Game::handle ( const sf::Event & event )
{
    this->interface.handle ( event ) ;
}
void Game::update ( const sf::Time & frameTime )
{
    this->interface.update ( frameTime ) ;

	this->map.update(frameTime);
}
void Game::draw ( sf::RenderTarget & target )
{
    this->interface.draw ( target ) ;
	this->map.draw(target);
}
