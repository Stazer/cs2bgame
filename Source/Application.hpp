#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "AudioManager.hpp"

class Application
{
	public :
      /* */
      int main ( const std::vector <std::string> & arguments ) ;

   private :
      AudioManager audioManager ;
      TextureManager textureManager ;
      FontManager fontManager ;
} ;
