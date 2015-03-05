/* for help look at:
 http://www.sfml-dev.org/tutorials/2.2/
 */

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "ResourceManager.hpp"
#include "Interface.hpp"

class AudioManager;

class Game
{
	public :
      Game (TextureManager& textureManager, AudioManager& audioManager, const sf::View & defaultView);

      const TextureManager& getTextureManager()const;
      TextureManager& getTextureManager();

      const AudioManager& getAudioManager()const;
      AudioManager& getAudioManager();

      const Interface& getInterface() const;
      Interface& getInterface();

      /*  */
      void handle ( const sf::Event & event ) ;
      /*  */
		void update ( const sf::Time & frameTime ) ;
      /*  */
		void draw ( sf::RenderTarget & target ) ;

    private :
      TextureManager& textureManager;
      AudioManager& audioManager;

      Map map;
      Interface interface;
} ;
