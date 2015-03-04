#include "Game.hpp"

Game::Game (const TextureManager& textureManager, const AudioManager& audioManager):
	textureManager(textureManager),
	audioManager(audioManager)
{
}

/*  */
void Game::handle ( const sf::Event & event )
{
}
void Game::update ( const sf::Time & frameTime )
{
}
void Game::draw ( sf::RenderTarget & target )
{
}
