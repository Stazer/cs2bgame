//
//  StaticEntity.cpp
//  cs2bgame
//
//  Created by Brendan Murray on 3/2/15.
//
//

#include "StaticEntity.hpp"

#include <stdio.h>

StaticEntity::StaticEntity ( Map & map ) : Entity (map) { }

StaticEntity::StaticEntity ( Map & map , const sf::Vector2f & position ,
                            const sf::Texture & texture ) : Entity(map) { }



void StaticEntity::pdate ( const sf::Time & frameTime ) { }
