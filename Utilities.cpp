//
//  Utilities.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "Utilities.h"

sf::Vector2f rotatePointAboutZero(sf::Vector2f point, double rotationDegrees)                 // Takes point with respect to origin to be rotated about. Tested and works
{
    float theta=(PI/180)*rotationDegrees;
    sf::Vector2f finalPosition;
    finalPosition.x=point.x*cos(theta)-point.y*sin(theta);
    finalPosition.y=point.x*sin(theta)+point.y*cos(theta);
    return finalPosition;
}

sf::Vector2f getPixelGlobalPosition(SolidObject & ob,float topleftX,float topleftY)         //Takes position of pixel with respect to top left corner as input
{
    sf::Vector2f originXY(topleftX-ob.getCenterOfMass().x, topleftY-ob.getCenterOfMass().y);              //Position of pixel with respect to origin
    sf::Vector2f rotatedoriginXY = rotatePointAboutZero(originXY, ob.getRotation());
    return rotatedoriginXY+ob.getPosition();                                                                          //Returns absolute position of pixel, accounting for all transformations of parent image
}

sf::Vector2f getPixelGlobalPosition(SolidObject & ob, sf::Vector2f topleft)
{
    sf::Vector2f rspctOrigin=topleft-ob.getCenterOfMass();
    sf::Vector2f rotatedRspctOrigin = rotatePointAboutZero(rspctOrigin, ob.getRotation());
    return rotatedRspctOrigin+ob.getPosition();
}
