//
//  StraightLine.h
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__StraightLine__
#define __SpaceGame__StraightLine__
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>
#include "StraightLine.h"
#include "Intersection.h"

//
class StraightLine{
public:
    StraightLine(double m, double c);
    StraightLine(sf::Vector2f point1, sf::Vector2f point2);
    StraightLine(double m, sf::Vector2f point);
    StraightLine();
    double getGradient();
    double get_y_Intercept();
    double getNormalGradient();
    StraightLine getNormalAtX(double x);
    Intersection intersects(StraightLine line2);
private:
    double _gradient;
    double _yIntercept;
};
// end

class LineSegment
{
public:
    sf::Vector2f point1;
    sf::Vector2f point2;
    LineSegment(sf::Vector2f p1, sf::Vector2f p2);      //CONSTRUCTOR

    LineSegment();
    float getLength();

    sf::Vector2f getMidpoint();

    double getGradient();
    double get_y_Intercept();
    void coutLinePoints();
    Intersection intersects(LineSegment lineB);
    Intersection intersects(StraightLine fullLine);
};


#endif /* defined(__SpaceGame__StraightLine__) */
