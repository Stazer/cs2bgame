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
      /* make sure ResourceManager is not able to be copied */
      ResourceManager ( const ResourceManager & ResourceManager ) = delete ;
      /* make sure ResourceManager is not able to be copied */
      ResourceManager & operator = ( const ResourceManager & ResourceManager ) =  delete ;

      /* add new file to resourceManager */
      void add ( const std::string & file ) ;
      void add ( const std::string & name , const std::string & file ) ;

      void remove ( const std::string & name ) ;

      Type & get ( const std::string & name ) ;
      const Type & get ( const std::string & name ) const ;

      bool exists ( const std::string & name ) const ;

	private :
      bool loadResource ( sf::Texture & resource , const std::string & file ) ;
      bool loadResource ( sf::SoundBuffer & resource , const std::string & file ) ;
      bool loadResource ( sf::Music & resource , const std::string & file ) ;

		std::unordered_map <std::string , std::shared_ptr <Type>> resources ;
} ;

using TextureManager = ResourceManager <sf::Texture> ;
using SoundBufferManager = ResourceManager <sf::SoundBuffer> ;
using MusicManager = ResourceManager <sf::Music> ;

#include "ResourceManager.inl"
