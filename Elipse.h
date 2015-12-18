//
//  Elipse.h
//  SpaceGame
//
//  Created by Jonathan Wood on 20/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__Elipse__
#define __SpaceGame__Elipse__
#include <SFML/Graphics.hpp>
#include "VectorMaths.h"
#include <cmath>

template <class T> class Elipse{
public:
    Elipse(sf::Vector2<T> focA, sf::Vector2<T> focB, T minorAxis)
    {
        focusA=focA;
        focusB=focB;
        T AB=magnitude(focA-focB);
        constant = 2*sqrt( (0.5*AB)*(0.5*AB) + (minorAxis/2)*(minorAxis/2));
    }
protected:
    T constant;
    sf::Vector2<T> focusA;
    sf::Vector2<T> focusB;
};

template <typename T>
sf::Vector2f Intersection(Elipse<T> elipse, StraightLine line)
{
    
}

/*
 
 to check if point P is inside of elipse:
 
 if(AP + BP < constant)
    return true
 
 */
#endif /* defined(__SpaceGame__Elipse__) */
