/* special file for implementing template classes */

template <typename Type>
void ResourceManager <Type>::add ( const std::string & file )
{
    // extract the filename from the given file parameter
    std::string name = file ;
    std::reverse ( name.begin ( ) , name.end ( ) ) ;
    name = name.substr ( 0 , name.find ( '/' ) ) ;
    std::reverse ( name.begin ( ) , name.end ( ) ) ;
    name = name.substr ( 0 , name.find ( '.' ) ) ;

    // add the file with the extracted name to resources
    this->add ( name , file ) ;
}
template <typename Type>
void ResourceManager <Type>::add ( const std::string & name , const std::string & file )
{
    this->loadResource ( this->resources [ name ] , file ) ;
}

template <typename Type>
void ResourceManager <Type>::remove ( const std::string & name )
{
    this->resources.erase ( this->Resources.find ( name ) ) ;
}

template <typename Type>
Type & ResourceManager <Type>::get ( const std::string & name )
{
    auto iterator = this->resources.find ( name ) ;

    if ( iterator == this->resources.end ( ) )
        throw std::out_of_range ( "\"" + name + "\" wasn't found inside the resource manager!" ) ;

    return iterator->second ;
}
template <typename Type>
const Type & ResourceManager <Type>::get ( const std::string & name ) const
{
    auto iterator = this->resources.find ( name ) ;

    if ( iterator == this->resources.end ( ) )
        throw std::runtime_error ( "The resource \"" + name + "\" wasn't found inside the resource manager!" ) ;

    return iterator->second ;
}

template <typename Type>
bool ResourceManager <Type>::exists ( const std::string & name ) const
{
    return this->resources.find ( name ) == this->resources.end ( ) ;
}

template <typename Type>
Type & ResourceManager <Type>::operator [ ] ( const std::string & name )
{
    return this->get ( name ) ;
}
template <typename Type>
const Type & ResourceManager <Type>::operator [ ] ( const std::string & name ) const
{
    return this->get ( name ) ;
}

template <typename Type>
bool ResourceManager <Type>::loadResource ( sf::Texture & resource , const std::string & file ) const
{
    return resource.loadFromFile ( file ) ;
}
template <typename Type>
bool ResourceManager <Type>::loadResource ( sf::SoundBuffer & resource , const std::string & file ) const
{
    return resource.loadFromFile ( file ) ;
}
template <typename Type>
bool ResourceManager <Type>::loadResource ( sf::Music & resource , const std::string & file ) const
{
    return resource.openFromFile ( file ) ;
}
template <typename Type>
bool ResourceManager <Type>::loadResource ( sf::Font & resource , const std::string & file ) const
{
    return resource.loadFromFile ( file ) ;
}