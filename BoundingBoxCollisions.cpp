//
//  BoundingBoxCollisions.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "BoundingBoxCollisions.h"

bool doBoundingBoxesIntersect(SolidObject& obA, SolidObject& obB)
{
    sf::FloatRect tempRectA=obA.getSprite().getGlobalBounds();
    sf::FloatRect tempRectB=obB.getSprite().getGlobalBounds();
    float biggestVcomponent = std::max( std::max(fabs(obA.getVelocity().x), fabs(obA.getVelocity().y)), std::max(fabs(obB.getVelocity().x), fabs(obB.getVelocity().y)));
    double steps=biggestVcomponent * SolidObject::dt;           //Distance Traveled by fastest v component in one frame 
    double steptime= SolidObject::dt/steps;                              //timestep such that the fastest component moves 1 pixel per step
    double t=steptime;
    while(t<=SolidObject::dt){
        if(tempRectA.intersects(tempRectB)){
            return true;
        }
        t+=steptime;
        tempRectA.left+=steptime*obA.getVelocity().x;
        tempRectA.top+=steptime*obA.getVelocity().y;
        tempRectB.left+=steptime*obB.getVelocity().x;
        tempRectB.top+=steptime*obB.getVelocity().y;
    }
    return false;
}