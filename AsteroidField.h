//
//  AsteroidField.h
//  SpaceGame
//
//  Created by Jonathan Wood on 12/11/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__AsteroidField__
#define __SpaceGame__AsteroidField__
#include <SFML/Graphics.hpp>
#include "SolidObject.h"
#include "BoundingBoxCollisions.h"
#include "RandomNumberGeneration.h"

class AsteroidField{
public:
    AsteroidField(SolidObject asteroidTemplate, sf::IntRect area);
    AsteroidField(){};
protected:
    float _density = 10;     //Asteroids per square km
    float _maxScale = 2.0;
    float _minScale = 0.5;
};

#endif /* defined(__SpaceGame__AsteroidField__) */
