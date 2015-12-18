//
//  CircleCollisions.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 18/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "CircleCollisions.h"

bool broadPhaseCircleObjectCollideCheck(Circle circ,  SolidObject& ob){
    return (magnitude(ob.getPosition()-circ.center) <= magnitude(ob.getSize())/2 + circ.radius);
}

Intersection circleObjectCollideCheck(Circle circ,  SolidObject& ob){
    for(int i=0 ; i<ob.getCollisionLinePoints().size()-1 ; i++){
        LineSegment tempLineA (getPixelGlobalPosition(ob, ob.getCollisionLinePoints()[i]) , getPixelGlobalPosition(ob, ob.getCollisionLinePoints()[i+1]));
        Intersection possibleIntersection = intersection(circ, tempLineA);
        if(possibleIntersection.isTrue == true)
            return possibleIntersection;
    }
    return Intersection(false, sf::Vector2f(0.0, 0.0));
}