//
//  RailGun.h
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__RailGun__
#define __SpaceGame__RailGun__
#include "Weapon.h"
#include "Slug.h"
#include "Utilities.h"

class RailGun: public Weapon{
public:
    void fire(SpaceCraft& ms);
    void setAmmo(Slug amo);
    float getLength();
    virtual std::string getType();

    RailGun(std::string nam, float A,float B, float Cr, sf::Vector2f centOfMass, sf::Sprite sprite, DestroyEffect deathEffect ,std::vector<sf::Vector2f> LinePoints, float len, float F, sf::Vector2f exit, long structint, unsigned int str, sf::Sound shotSound, Material mat, float loadTime);
    RailGun();
    
private:
    float _length;
    unsigned int _force;
    Slug _ammo;
    sf::Vector2f _exitPoint;
    sf::Sound _fireSound;

};


#endif /* defined(__SpaceGame__RailGun__) */
