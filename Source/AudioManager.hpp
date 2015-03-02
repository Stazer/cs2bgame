#pragma once

#include <map>
#include <memory>
#include <SFML/Audio.hpp>
#include "ResourceManager.hpp"

class AudioManager
{
   private :
      std::unordered_multimap <std::string , std::shared_ptr <sf::Sound>> sounds ;

      SoundBufferManager soundBufferManager ;
      MusicManager musicManager ;

   public :
      AudioManager ( ) ;

      sf::Sound & getSound ( const std::string & name , sf::Sound::Status status = sf::Sound::Stopped ) ;
      const sf::Sound & getSound ( const std::string & name , sf::Sound::Status status = sf::Sound::Stopped ) const ;

      sf::Music & getMusic ( const std::string & name ) ;
      const sf::Music & getMusic ( const std::string & name ) const ;

      SoundBufferManager & getSoundBufferManager ( ) ;
      const SoundBufferManager & getSoundBufferManager ( ) const ;

      MusicManager & getMusicManager ( ) ;
      const MusicManager & getMusicManager ( ) const ;
} ;