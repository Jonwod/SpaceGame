//
//  StraightLine.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 03/10/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "StraightLine.h"



StraightLine::StraightLine(double m, double c){
    _gradient = m;
    _yIntercept = c;
}

StraightLine::StraightLine(sf::Vector2f point1, sf::Vector2f point2){
    if(point1.x == point2.x)
        _gradient = 214748364;       //Abitrary large number
    else{
        _gradient = (point2.y-point1.y)/(point2.x-point1.x);
        _yIntercept = -_gradient * point1.x + point1.y;
    }
}

StraightLine::StraightLine(double m, sf::Vector2f point){
    _gradient = m;
    _yIntercept = -m * point.x + point.y;
}

StraightLine::StraightLine(){
    _gradient = 0;
    _yIntercept = 0;
}

double StraightLine::getGradient(){
    return _gradient;
}

double StraightLine::get_y_Intercept(){
    return _yIntercept;
}

double StraightLine::getNormalGradient(){
    if (_gradient !=0 )
        return -1/_gradient;
    else
        return 214748364;
}

StraightLine StraightLine::getNormalAtX(double x){
    double ypoint = _gradient * x + _yIntercept;
    return StraightLine(getNormalGradient(), -getNormalGradient() * x + ypoint);
}

//  Will fail if either line is vertical
Intersection StraightLine::intersects(StraightLine line2){
    if(_gradient == line2.getGradient())
        return Intersection(false, sf::Vector2f(0.0, 0.0));
    double interceptx = (line2.get_y_Intercept() - _yIntercept) / (_gradient - line2.getGradient());
    double intercepty = _gradient * interceptx + _yIntercept;
    return Intersection(true, sf::Vector2f(interceptx, intercepty));
}