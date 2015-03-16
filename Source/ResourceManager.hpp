#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <iostream>

template <typename Type>
class ResourceManager
{
    public :
        ResourceManager ( ) = default ;
        ResourceManager ( const ResourceManager & ResourceManager ) = delete ;
        ResourceManager & operator = ( const ResourceManager & ResourceManager ) =  delete ;

        void add ( const std::string & file ) ;
        void add ( const std::string & name , const std::string & file ) ;

        void remove ( const std::string & name ) ;

        Type & get ( const std::string & name ) ;
        const Type & get ( const std::string & name ) const ;

        bool exists ( const std::string & name ) const ;

	private :
        bool loadResource ( sf::Texture & resource , const std::string & file ) const ;
        bool loadResource ( sf::SoundBuffer & resource , const std::string & file ) const ;
        bool loadResource ( sf::Music & resource , const std::string & file ) const ;
        bool loadResource ( sf::Font & resource , const std::string & file ) const ;

        std::unordered_map <std::string , std::shared_ptr <Type>> resources ;
} ;

using TextureManager = ResourceManager <sf::Texture> ;
using SoundBufferManager = ResourceManager <sf::SoundBuffer> ;
using MusicManager = ResourceManager <sf::Music> ;
using FontManager = ResourceManager <sf::Font> ;

#include "ResourceManager.inl"
