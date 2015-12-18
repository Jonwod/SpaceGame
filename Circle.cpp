//
//  Circle.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 14/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "Circle.h"
#include "VectorMaths.h"
Circle::Circle(sf::Vector2f cntr, float rad){
    radius=rad;
    center=cntr;
}
Circle::Circle(float rad, sf::Vector2f cntr){
    radius=rad;
    center=cntr;
}
Circle::Circle(){
    radius=0;
    center=sf::Vector2f(0, 0);
}

Intersection intersection(Circle circ, LineSegment line){
    if(magnitude(line.point1-circ.center)<circ.radius)
        return Intersection(true, line.point1);
    if(magnitude(line.point2-circ.center)<circ.radius)
        return Intersection(true, line.point2);
    
    StraightLine normalLine = StraightLine(line.point1, line.point2).getNormalAtX(circ.center.x);
    sf::Vector2f radiusIntersectPoint = line.intersects(normalLine).point;
    if(magnitude(circ.center-radiusIntersectPoint) > circ.radius)
        return Intersection(false, sf::Vector2f(0.0, 0.0));
    
    return Intersection(false, radiusIntersectPoint);
}

Intersection intersection(LineSegment line, Circle circ){
    if(magnitude(line.point1-circ.center)<circ.radius)
        return Intersection(true, line.point1);
    if(magnitude(line.point2-circ.center)<circ.radius)
        return Intersection(true, line.point2);
    
    StraightLine normalLine = StraightLine(line.point1, line.point2).getNormalAtX(circ.center.x);
    sf::Vector2f radiusIntersectPoint = line.intersects(normalLine).point;
    if(magnitude(circ.center-radiusIntersectPoint) > circ.radius)
        return Intersection(false, sf::Vector2f(0.0, 0.0));
    
    return Intersection(false, radiusIntersectPoint);
}
