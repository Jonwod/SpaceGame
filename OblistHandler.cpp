//
//  ObListHandler.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 13/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "OblistHandler.h"

void collisionHandler(){
    for(int i=0 ; i<SolidObject::ObList.size() ; i++){
        //  changed from for(int j=1 ; (j+i)<SolidObject::ObList.size() ;  j++){
        for(int j= i + 1; j <SolidObject::ObList.size() ;  j++){
            if (doBoundingBoxesIntersect(*SolidObject::ObList[i], *SolidObject::ObList[j]) == true){
                Intersection possibleIntersection = calculateGeometryIntersect(*SolidObject::ObList[i], *SolidObject::ObList[j]);
                if(possibleIntersection.isTrue == true){
                        if(SolidObject::ObList[i]->getFramesSinceLastCollision()>5 && SolidObject::ObList[j]->getFramesSinceLastCollision()>5){
                            collide(*SolidObject::ObList[i], *SolidObject::ObList[j], possibleIntersection.point);
                            seperate(*SolidObject::ObList[i], *SolidObject::ObList[j]);
                        }
                }
            }
        }
    }
}