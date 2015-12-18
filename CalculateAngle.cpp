//
//  CalculateAngle.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 04/11/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "CalculateAngle.h"

double calculateBearingFromAtoB(sf::Vector2f A, sf::Vector2f B){
    const double radsToDegrees = 180/PI;
    double dy = B.y - A.y;
    double dx = B.x - A.x;
    double theta = atan(dy / dx) * radsToDegrees;
    if(B.x < A.x)
        theta += 180;
    if(theta < 0)
        theta += 360;                       //Ensures return value is greater than zero
    return theta;
}
