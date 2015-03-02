#include "AudioManager.hpp"
#include <stdexcept>
#include <memory>

AudioManager::AudioManager ( )
{
    this->sounds.insert ( { "" , std::shared_ptr <sf::Sound> ( new sf::Sound ( ) ) } ) ;
}

sf::Sound & AudioManager::getSound ( const std::string & name , sf::Sound::Status status )
{
    // try to find an element that meets the requirements of an equal name and the requested status
    for ( auto & sound : this->sounds )
    {
        if ( sound.first == name && sound.second->getStatus ( ) == status )
            return * sound.second ;
    }

    // take any element that has been stopped, assign a new sound buffer to it and return it
    for ( auto & sound : this->sounds )
    {
        if ( sound.second->getStatus ( ) == sf::Sound::Stopped )
        {
            sound.second->setBuffer ( this->soundBufferManager.get ( name ) ) ;
            return * sound.second ;
        }
    }

    // if the size is smaler that 256 create a new sound, assign a sound buffer to it and return it
    if ( this->sounds.size ( ) < 0xFF )
    {
        sf::Sound * pointer ( new sf::Sound ( ) ) ;

        pointer->setBuffer ( this->soundBufferManager.get ( name ) ) ;

        this->sounds.insert ( { name , std::shared_ptr <sf::Sound> ( pointer ) } ) ;

        return * pointer ;
    }

    // if no requirements were met return the default sound
    return * this->sounds.begin ( )->second ;
}
const sf::Sound & AudioManager::getSound ( const std::string & name , sf::Sound::Status status ) const
{
    for ( auto & sound : this->sounds )
    {
        if ( sound.first == name && sound.second->getStatus ( ) == status )
            return * sound.second ;
    }

    throw std::out_of_range ( name + " does not exist!" ) ;

    /* hack for vs */
    return * this->sounds.begin ( )->second ;
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
