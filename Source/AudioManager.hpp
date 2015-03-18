#pragma once

#include <map>
#include <memory>
#include <SFML/Audio.hpp>
#include "ResourceManager.hpp"

class AudioManager
{
   private :
      std::unordered_multimap <std::string , sf::Sound> sounds ;

      sf::Sound defaultSound ;

      SoundBufferManager soundBufferManager ;
      MusicManager musicManager ;

   public :
      sf::Sound & getSound ( const std::string & name , sf::Sound::Status status = sf::Sound::Stopped ) ;
      const sf::Sound & getSound ( const std::string & name , sf::Sound::Status status = sf::Sound::Stopped ) const ;

      sf::Music & getMusic ( const std::string & name ) ;
      const sf::Music & getMusic ( const std::string & name ) const ;

      SoundBufferManager & getSoundBufferManager ( ) ;
      const SoundBufferManager & getSoundBufferManager ( ) const ;

      MusicManager & getMusicManager ( ) ;
      const MusicManager & getMusicManager ( ) const ;
} ;