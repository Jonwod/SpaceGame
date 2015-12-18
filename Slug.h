//
//  Slug.h
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__Slug__
#define __SpaceGame__Slug__
#include "SolidObject.h"

class Slug: public SolidObject{
public:
    Slug(std::string nam, float mass, float momentOfInertia, float elasticity, sf::Vector2f centerOfMass, sf::Sprite sprite, DestroyEffect deathEffect, sf::Sound deathSound,
         std::vector<sf::Vector2f> LinePoints, long structint, unsigned int structStrength, Material mat);
    virtual void update();
    virtual void updateStatus();
    Slug();
private:
    double _lifeTimer;

};

#endif /* defined(__SpaceGame__Slug__) */
