//
//  LineCollisions.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "LineCollisions.h"
Intersection calculateGeometryIntersect(SolidObject ob1, SolidObject ob2)
{
    SolidObject obA, obB;
    if(magnitude(ob1.getSize())<magnitude(ob2.getSize())){
        obA=ob1;
        obB=ob2;
    }
    else{
        obA=ob2;
        obB=ob1;
    }
    sf::Vector2f vARelativeB=multiply((obA.getVelocity()-obB.getVelocity()), float(SolidObject::dt));
    for (int i=0 ; i<(obA.getCollisionLinePoints().size()-1) ; i++)
    {
        LineSegment tempLineA (getPixelGlobalPosition(obA, obA.getCollisionLinePoints()[i]) ,getPixelGlobalPosition(obA, obA.getCollisionLinePoints()[i+1]));
        LineSegment vLineA(tempLineA.point1, tempLineA.point1+vARelativeB);
        for(int j=0 ; j<(obB.getCollisionLinePoints().size()-1) ; j++)
        {
            LineSegment tempLineB (getPixelGlobalPosition(obB, obB.getCollisionLinePoints()[j]), getPixelGlobalPosition(obB, obB.getCollisionLinePoints()[j+1]));
            Intersection tempLinesABintersect = tempLineA.intersects(tempLineB);
            if(tempLinesABintersect.isTrue)
                return tempLinesABintersect;
            Intersection vLineAtempLineBintersection = vLineA.intersects(tempLineB);
            if(vLineAtempLineBintersection.isTrue)
                return vLineAtempLineBintersection;
        }
    }
    return Intersection(false, sf::Vector2f(0.0, 0.0));
}
