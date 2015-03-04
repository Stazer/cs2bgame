#include "Game.hpp"

Game::Game (TextureManager& textureManager, AudioManager& audioManager):
	textureManager(textureManager),
	audioManager(audioManager),
	map(*this),
	interface(*this)
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

/*  */
void Game::handle ( const sf::Event & event )
{
}
void Game::update ( const sf::Time & frameTime )
{
	this->map.update(frameTime);
}
void Game::draw ( sf::RenderTarget & target )
{
	this->map.draw(target);
}
