//
//  StraightLine.h
//  SpaceGame
//
//  Created by Jonathan Wood on 03/10/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__StraightLine__
#define __SpaceGame__StraightLine__
#include <SFML/System/Vector2.hpp>
#include "Intersection.h"
#include <limits>

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

#endif /* defined(__SpaceGame__StraightLine__) */
