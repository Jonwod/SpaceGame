//
//  Material.h
//  SpaceGame
//
//  Created by Jonathan Wood on 02/10/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__Material__
#define __SpaceGame__Material__
#include <SFML/Audio.hpp>
class Material{
public:
    void playImpactSoundAt(sf::Vector2f point);
    Material(sf::Sound sound);
private:
    sf::Sound impactSound;
};
#endif /* defined(__SpaceGame__Material__) */
