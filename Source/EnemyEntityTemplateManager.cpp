#include "EnemyEntityTemplateManager.hpp"
#include <sstream>
#include <fstream>

void EnemyEntityTemplateManager::readFile ( const std::string & fileName )
{
    std::ifstream file ( fileName.c_str ( ) ) ;

    if ( ! file.is_open ( ) )
        return ;

    for ( std::string line ; std::getline ( file , line ) ; )
    {
        std::stringstream stream ( line ) ;

        EnemyEntityTemplate newTemplate ;
        newTemplate.parse ( stream ) ;

        this->enemyEntityTemplates.push_back ( newTemplate ) ;
    }
}

EnemyEntity * EnemyEntityTemplateManager::createRandomEnemyEntity ( Map & map , const sf::Vector2f & position ) const
{
    return this->enemyEntityTemplates [ rand ( ) % this->enemyEntityTemplates.size ( ) ].createEnemyEntity ( map , position ) ;
}