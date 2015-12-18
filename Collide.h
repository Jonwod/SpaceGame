//
//  Collide.h
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__Collide__
#define __SpaceGame__Collide__
#include <cmath>
#include <math.h>
#include "LineSegment.h"
#include "SolidObject.h"
#define PI 3.14159265

void damageResolve(SolidObject& obA, SolidObject& obB);

void collide(SolidObject& obA, SolidObject& obB, sf::Vector2f collidePoint);

void seperate(SolidObject& obA, SolidObject& obB);

#endif /* defined(__SpaceGame__Collide__) */
