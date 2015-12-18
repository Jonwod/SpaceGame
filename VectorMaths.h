//
//  VectorMaths.h
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__VectorMaths__
#define __SpaceGame__VectorMaths__

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>

template <typename T>
T magnitude(sf::Vector2<T> A)
{
    return sqrt(pow(A.x, 2)+pow(A.y, 2));
}

template <typename T>
T dotProduct(sf::Vector3<T> A, sf::Vector3<T> B)
{
    return (A.x*B.x+A.y*B.y+A.z*B.z);
}

template <typename T>
T dotProduct(sf::Vector2<T> A, sf::Vector2<T> B)
{
    return (A.x*B.x+A.y*B.y);
}

template <typename T>
sf::Vector3<T> crossProduct(sf::Vector3<T> A, sf::Vector3<T> B)
{
    T Cx=A.y*B.z-A.z*B.y;
    T Cy=A.z*B.x-A.x*B.z;
    T Cz=A.x*B.y-A.y*B.x;
    return sf::Vector3<T>(Cx, Cy, Cz);
}

template <typename T>
T crossProduct(sf::Vector2<T> a, sf::Vector2<T> b)
{
    return a.x * b.y - a.y * b.x;
}

template <typename T>
sf::Vector2<T> crossProduct( sf::Vector2<T> a, T s )
{
    return sf::Vector2<T>( s*a.y, -s*a.x );
}

template <typename T>
sf::Vector2<T> crossProduct(T s,  sf::Vector2<T> a)
{
    return sf::Vector2<T>( -s*a.y, s*a.x);
}

template <typename T>
sf::Vector2<T> multiply(sf::Vector2<T> Vec, T scal)
{
    return sf::Vector2<T>(Vec.x*scal ,Vec.y*scal);
}

template <typename T>
sf::Vector2<T> multiply(T scal, sf::Vector2<T> vec)
{
    return sf::Vector2<T>(vec.x*scal, vec.y*scal);
}

#endif /* defined(__SpaceGame__VectorMaths__) */
