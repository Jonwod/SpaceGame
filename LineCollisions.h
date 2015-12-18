//
//  LineCollisions.h
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__LineCollisions__
#define __SpaceGame__LineCollisions__

#include <cmath>
#include <SFML/Graphics.hpp>
#include "LineSegment.h"
#include "Utilities.h"
#define PI 3.14159265

Intersection calculateGeometryIntersect(SolidObject ob1, SolidObject ob2);

#endif /* defined(__SpaceGame__LineCollisions__) */
