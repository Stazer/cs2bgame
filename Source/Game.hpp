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
        Game ( TextureManager & textureManager , AudioManager & audioManager , FontManager & fontManager , sf::RenderWindow & target ) ;
        Game ( const Game & game ) = delete ;

		Game & operator = ( const Game & game ) = delete ;

        const TextureManager & getTextureManager ( ) const ;
        TextureManager & getTextureManager ( ) ;

        const AudioManager & getAudioManager ( ) const ;
        AudioManager & getAudioManager ( ) ;

        const FontManager & getFontManager ( ) const ;
        FontManager & getFontManager ( ) ;

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
        void addKill ( ) ;

        const sf::Clock & getTimer ( ) const ;

        /*  */
        void handle ( const sf::Event & event ) ;
        /*  */
        void update ( const sf::Time & frameTime ) ;
        /*  */
        void draw ( sf::RenderTarget & target ) ;

    private :
        void play ( ) ;
        void stop ( ) ;

        TextureManager & textureManager ;
        AudioManager & audioManager ;
        FontManager & fontManager ;

        sf::Sprite instructions ;

        bool isPlaying = false ;

        unsigned int kills = 0 ;
        sf::Clock timer ;

        EnemyEntityTemplateManager enemyEntityTemplateManager ;

        Player player ;
        Map map ;
        Interface interface;
} ;
