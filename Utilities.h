//
//  Utilities.h
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__Utilities__
#define __SpaceGame__Utilities__
#include "SolidObject.h"

sf::Vector2f rotatePointAboutZero(sf::Vector2f point, double rotationDegrees);                 // Takes point with respect to origin to be rotated about. Tested and works

sf::Vector2f getPixelGlobalPosition(SolidObject & ob,float topleftX,float topleftY);         //Takes position of pixel with respect to top left corner as input

sf::Vector2f getPixelGlobalPosition(SolidObject & ob, sf::Vector2f topleft);

int getRandomIntInRange(int n1, int n2);
#endif /* defined(__SpaceGame__Utilities__) */
