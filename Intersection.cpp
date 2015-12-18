//
//  Intersection.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 30/10/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "Intersection.h"
Intersection::Intersection(bool occurs, sf::Vector2f atPoint){
    isTrue = occurs;
    point = atPoint;
}

Intersection::Intersection(sf::Vector2f atPoint, bool occurs){
    isTrue = occurs;
    point = atPoint;
}