#include "AudioManager.hpp"
#include <stdexcept>
#include <memory>

sf::Sound & AudioManager::getSound ( const std::string & name , sf::Sound::Status status )
{
    // try to find an element that meets the requirements of an equal name and the requested status
    for ( auto & sound : this->sounds )
    {
        if ( sound.first == name && sound.second.getStatus ( ) == status )
            return sound.second ;
    }

    // try to take any element that has been stopped, assign a new sound buffer to it and return it
    for ( auto & sound : this->sounds )
    {
        if ( sound.second.getStatus ( ) == sf::Sound::Stopped )
        {
            sound.second.setBuffer ( this->soundBufferManager.get ( name ) ) ;
            return sound.second ;
        }
    }

    // if the size is smaller than 255 then create a new sound, assign a sound buffer to it and return it
    // 255 is the maximum amount of sounds that can be played at the same time
    if ( this->sounds.size ( ) < 0xFF )
    {
        sf::Sound newSound ;
        newSound.setBuffer ( this->soundBufferManager.get ( name ) ) ;

        return this->sounds.insert ( { name , newSound } )->second ;
    }

    // if no requirements were met return the default sound
    return this->defaultSound ;
}
const sf::Sound & AudioManager::getSound ( const std::string & name , sf::Sound::Status status ) const
{
    for ( auto & sound : this->sounds )
    {
        if ( sound.first == name && sound.second.getStatus ( ) == status )
            return  sound.second ;
    }

    return this->defaultSound ;
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
