#include "EnemyEntityTemplateManager.hpp"
#include <sstream>
#include <fstream>

void EnemyEntityTemplateManager::readFile ( const std::string & fileName )
{
    // clear all enemyentitytemplates
    this->enemyEntityTemplates.clear ( ) ;

    // open the file and read it only if its opened
    std::ifstream file ( fileName.c_str ( ) ) ;
    if ( ! file.is_open ( ) )
        return ;

    // read text files line by line
    for ( std::string line ; std::getline ( file , line ) ; )
    {
        // read the line into a stream and read it
        std::stringstream stream ( line ) ;
        EnemyEntityTemplate newTemplate ;
        newTemplate.parse ( stream ) ;

        // push the new template to our vector
        this->enemyEntityTemplates.push_back ( newTemplate ) ;
    }
}

EnemyEntity * EnemyEntityTemplateManager::createRandomEnemyEntity ( Map & map , const sf::Vector2f & position ) const
{
    // take a random element from the enemyentitestemplates
    return this->enemyEntityTemplates [ rand ( ) % this->enemyEntityTemplates.size ( ) ].createEnemyEntity ( map , position ) ;
}