//
//  Intersection.h
//  SpaceGame
//
//  Created by Jonathan Wood on 30/10/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__Intersection__
#define __SpaceGame__Intersection__
#include <SFML/System/Vector2.hpp>

struct Intersection{
    bool isTrue;
    sf::Vector2f point;
    Intersection(bool, sf::Vector2f);
    Intersection(sf::Vector2f, bool);
};

#endif /* defined(__SpaceGame__Intersection__) */
