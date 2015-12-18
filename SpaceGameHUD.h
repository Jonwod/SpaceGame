//
//  SpaceGameHUD.h
//  SpaceGame
//
//  Created by Jonathan Wood on 13/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__SpaceGameHUD__
#define __SpaceGame__SpaceGameHUD__
#include <string>
#include "HUD.h"
#include "PlayerSpaceCraft.h"

class SpaceGameHUD: public HUD
{
    PlayerSpaceCraft playShip;
    HUDtext structIntPercentText;
    HUDtext vxText;
    HUDtext vyText;
    HUDtext vmagText;
public:
    SpaceGameHUD(const PlayerSpaceCraft& ps);
    void update(const sf::View& view, sf::Vector2i screenSize,PlayerSpaceCraft& ps);
};

#endif /* defined(__SpaceGame__SpaceGameHUD__) */
