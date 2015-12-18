//
//  Circle.h
//  SpaceGame
//
//  Created by Jonathan Wood on 14/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__Circle__
#define __SpaceGame__Circle__
#include <SFML/System/Vector2.hpp>
#include "LineSegment.h"
#include "Intersection.h"
class Circle{
public:
    float radius;
    sf::Vector2f center;
    Circle(float, sf::Vector2f);
    Circle(sf::Vector2f, float);
    Circle();
};

Intersection intersection(Circle circ, LineSegment line);
Intersection intersection(LineSegment, Circle);

#endif /* defined(__SpaceGame__Circle__) */
