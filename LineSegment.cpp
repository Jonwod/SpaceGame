//
//  StraightLine.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "LineSegment.h"
#include "Intersection.h"

//Prevents creation of vertical lines
LineSegment::LineSegment(sf::Vector2f p1, sf::Vector2f p2){
    point1=p1;
    point2=p2;
    if(p1.x == p2.x)
        p1.x += 0.01;
}

LineSegment::LineSegment(){
    point1=sf::Vector2f(0, 0);
    point2=sf::Vector2f(0, 0);
}


float LineSegment::getLength(){
    return sqrt(pow((point1.x-point2.x), 2) + pow(point1.y-point2.y, 2));
}

sf::Vector2f LineSegment::getMidpoint(){
    return sf::Vector2f( (point1.x+point2.x)/2, (point1.y+point2.y)/2 );
}

double LineSegment::getGradient(){
    return (point2.y-point1.y) / (point2.x-point1.x);
}

double LineSegment::get_y_Intercept(){
    return  point1.y - getGradient() * point1.x;
}


void LineSegment::coutLinePoints(){
    std::cout<<"point1:( "<<point1.x<<", "<<point1.y<<") point2:( "<<point2.x<<", "<<point2.y<<")";
}


Intersection LineSegment::intersects(LineSegment lineB){
    double mA = getGradient();
    double mB = lineB.getGradient();
    if(mA == mB){
        if(get_y_Intercept() != lineB.get_y_Intercept())
            return Intersection(false, sf::Vector2f(0.0, 0.0));
        else{
            if(getLength() <= lineB.getLength())
                return Intersection(true, getMidpoint());
            else
                return Intersection(true, lineB.getMidpoint());
        }
    }
    StraightLine fullLineA (mA, get_y_Intercept());
    StraightLine fullLineB (mB, lineB.get_y_Intercept());
    sf::Vector2f intersectPoint = fullLineA.intersects(fullLineB).point;
    
    if(intersectPoint.x <= std::max(point1.x, point2.x)  &&  intersectPoint.x >= std::min(point1.x, point2.x)){
        if(intersectPoint.y <= std::max(point1.y, point2.y)  &&  intersectPoint.y >= std::min(point1.y, point2.y)){                                             //Potentially unnessecary, optomize
            if(intersectPoint.x <= std::max(lineB.point1.x, lineB.point2.x)  &&  intersectPoint.x >= std::min(lineB.point1.x, lineB.point2.x)){
                if(intersectPoint.y <= std::max(lineB.point1.y, lineB.point2.y)  &&  intersectPoint.y >= std::min(lineB.point1.y, lineB.point2.y)){     //Dito
                    return Intersection(true, intersectPoint);
                }
            }
        }
    }
    return Intersection(sf::Vector2f(0.0, 0.0), false);
}

Intersection LineSegment::intersects(StraightLine fullLine){
    double m = getGradient();
    double mfullLine = fullLine.getGradient();
    if(m == mfullLine)
        return Intersection(sf::Vector2f(0.0, 0.0), false);
    StraightLine thisLine (m, get_y_Intercept());
    sf::Vector2f intersectPoint = thisLine.intersects(fullLine).point;
    if(intersectPoint.x > std::max(point1.x, point2.x) || intersectPoint.x < std::min(point1.x, point2.x))
        return Intersection(false, sf::Vector2f(0.0, 0.0));
    return Intersection(true, intersectPoint);
}