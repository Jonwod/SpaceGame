//
//  ModifiedSpaceCraft.h
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__ModifiedSpaceCraft__
#define __SpaceGame__ModifiedSpaceCraft__

#include <vector>
#include "RailGun.h"

class ModifiedSpaceCraft: public SpaceCraft{
public:
    //controls
    void fireAllWeapons();
    //end controls
    void attachWeapon(Weapon& weap ,int slot);
    void updateWeapons();
    virtual void update();
    ModifiedSpaceCraft(std::string nam, float mass,float momentOfInertia,float elasticity ,sf::Vector2f centerOfMass, sf::Sprite sprite, DestroyEffect deathEffect,
                       sf::Sound deathSound ,sf::Texture& flametex, std::vector<sf::Vector2f> LinePoints , float thrustarray[6],
                       sf::Sound thrustsoundarray[6], std::vector<WeaponSlot*> weapSlots, long structint, unsigned int str, Material mat);
    ModifiedSpaceCraft();
protected:
    std::vector<WeaponSlot*> _weaponSlots;
};


#endif /* defined(__SpaceGame__ModifiedSpaceCraft__) */
