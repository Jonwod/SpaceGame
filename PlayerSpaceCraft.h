//
//  PlayerSpaceCraft.h
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__PlayerSpaceCraft__
#define __SpaceGame__PlayerSpaceCraft__

#include "ModifiedSpaceCraft.h"

class PlayerSpaceCraft: public ModifiedSpaceCraft{
public:
    void getInput();
    
    virtual void update();
    PlayerSpaceCraft(std::string nam, float mass, float momentOfInertia, float elassticity, sf::Vector2f centerOfMass, sf::Sprite sprite, DestroyEffect deathEffect,
                     sf::Sound deathSound, sf::Texture& flametex, std::vector<sf::Vector2f> LinePoints, float thrustarray[6],
                     sf::Sound thrustsoundarray[6], std::vector<WeaponSlot*> weapSlots, long structint, unsigned int str, Material mat);
    
    PlayerSpaceCraft();
private:
    bool _keyIreset=true;
};

#endif /* defined(__SpaceGame__PlayerSpaceCraft__) */
