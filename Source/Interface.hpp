#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "ResourceManager.hpp"

class AudioManager;
class Game;

class Interface
{
   public :
      Interface (const TextureManager& textureManager, const AudioManager& audioManager);

      /*  */
      void handle ( const sf::Event & event ) ;
      /*  */
      void update ( const sf::Time & frameTime ) ;
      /*  */
      void draw ( sf::RenderTarget & target ) ;

   private:
      Game& game;
} ;
