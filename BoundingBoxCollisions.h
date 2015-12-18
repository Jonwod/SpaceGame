//
//  BoundingBoxCollisions.h
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__BoundingBoxCollisions__
#define __SpaceGame__BoundingBoxCollisions__
#include <SFML/Graphics.hpp>
#include <cmath>
#include <algorithm>
#include "SolidObject.h"


bool doBoundingBoxesIntersect(SolidObject& obA, SolidObject& obB);

#endif /* defined(__SpaceGame__BoundingBoxCollisions__) */
