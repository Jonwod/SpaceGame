//
//  CircleCollisions.h
//  SpaceGame
//
//  Created by Jonathan Wood on 18/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__CircleCollisions__
#define __SpaceGame__CircleCollisions__
#include "Circle.h"
#include "Utilities.h"

bool broadPhaseCircleObjectCollideCheck(Circle circ,  SolidObject& ob);       //Broad Phase

Intersection circleObjectCollideCheck(Circle circ,  SolidObject& ob);        //Narrow Phase

#endif /* defined(__SpaceGame__CircleCollisions__) */
