#include "AudioManager.hpp"

sf::Sound & AudioManager::getSound ( const std::string & name , sf::Sound::Status status )
{
    return *this->sounds.begin ( )->second ;
	// implement me :)
}
const sf::Sound & AudioManager::getSound ( const std::string & name , sf::Sound::Status status ) const
{
    return *this->sounds.begin ( )->second ;
	// implement me :)
}

sf::Music & AudioManager::getMusic ( const std::string & name )
{
    return this->musicManager.get ( name ) ;
}
const sf::Music & AudioManager::getMusic ( const std::string & name ) const
{
    return this->musicManager.get ( name ) ;
}

SoundBufferManager & AudioManager::getSoundBufferManager ( )
{
    return this->soundBufferManager ;
}
const SoundBufferManager & AudioManager::getSoundBufferManager ( ) const
{
    return this->soundBufferManager ;
}

MusicManager & AudioManager::getMusicManager ( )
{
    return this->musicManager ;
}
const MusicManager & AudioManager::getMusicManager ( ) const
{
    return this->musicManager ;
}
