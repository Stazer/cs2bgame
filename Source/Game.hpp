#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "EnemyEntityTemplateManager.hpp"
#include "Map.hpp"
#include "ResourceManager.hpp"
#include "Interface.hpp"
#include "Player.hpp"

class AudioManager;

class Game
{
	public :
        Game ( TextureManager & textureManager , AudioManager & audioManager , const sf::RenderTarget & target , const std::string & creaturesFileName ) ;

        const TextureManager & getTextureManager ( ) const ;
        TextureManager & getTextureManager ( ) ;

        const AudioManager & getAudioManager ( ) const ;
        AudioManager & getAudioManager ( ) ;

        const Map & getMap ( ) const ;
        Map & getMap ( ) ;

        const Player & getPlayer ( ) const ;
        Player & getPlayer ( ) ;

        const Interface & getInterface ( ) const ;
        Interface & getInterface ( ) ;

        EnemyEntityTemplateManager & getEnemyEntityTemplateManager ( ) ;
        const EnemyEntityTemplateManager & getEnemyEntityTemplateManager ( ) const ;

        void setKills ( unsigned int kills ) ;
        unsigned int getKills ( ) const ;

        /*  */
        void handle ( const sf::Event & event ) ;
        /*  */
        void update ( const sf::Time & frameTime ) ;
        /*  */
        void draw ( sf::RenderTarget & target ) ;

    private :
        TextureManager & textureManager ;
        AudioManager & audioManager ;

        unsigned int kills = 0 ;

        EnemyEntityTemplateManager enemyEntityTemplateManager ;

        Player player ;
        Map map ;
        Interface interface;
} ;