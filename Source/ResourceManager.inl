template <typename Type>
void ResourceManager <Type>::add ( const std::string & file )
{
    std::string name = file ;
    std::reverse ( name.begin ( ) , name.end ( ) ) ;

    name = name.substr ( 0 , name.find ( '/' ) ) ;

    std::reverse ( name.begin ( ) , name.end ( ) ) ;

    name = name.substr ( 0 , name.find ( '.' ) ) ;

    this->add ( name , file ) ;
}
template <typename Type>
void ResourceManager <Type>::add ( const std::string & name , const std::string & file )
{
    this->resources [ name ] = std::unique_ptr <Type> ( new Type ( ) ) ;

    this->loadResource ( * this->resources [ name ] , file ) ;
}

template <typename Type>
void ResourceManager <Type>::remove ( const std::string & name )
{
    this->resources.erase ( this->Resources.find ( name ) ) ;
}

template <typename Type>
Type & ResourceManager <Type>::get ( const std::string & name )
{
    return * this->resources [ name ] ;
}
template <typename Type>
const Type & ResourceManager <Type>::get ( const std::string & name ) const
{
    return * this->resources.at ( name ) ;
}

template <typename Type>
bool ResourceManager <Type>::exists ( const std::string & name ) const
{
    return this->resources.find ( name ) == this->resources.end ( ) ;
}

template <typename Type>
bool ResourceManager <Type>::loadResource ( sf::Texture & Resource , const std::string & file )
{
    return Resource.loadFromFile ( file ) ;
}
template <typename Type>
bool ResourceManager <Type>::loadResource ( sf::SoundBuffer & Resource , const std::string & file )
{
    return Resource.loadFromFile ( file ) ;
}
template <typename Type>
bool ResourceManager <Type>::loadResource ( sf::Music & Resource , const std::string & file )
{
    return Resource.openFromFile ( file ) ;
}