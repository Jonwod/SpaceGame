//
//  FollowCam.h
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__FollowCam__
#define __SpaceGame__FollowCam__
#include <cmath>
#include "SFML/Audio.hpp"
#include "SolidObject.h"

void cameraUpdate(sf::Vector2i screenSize,sf::View& view ,SolidObject& playship);  //Takes the window,  main view and the players ship. ship must start at center of view.

#endif /* defined(__SpaceGame__FollowCam__) */
