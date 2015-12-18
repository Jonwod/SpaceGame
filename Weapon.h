//
//  Weapon.h
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__Weapon__
#define __SpaceGame__Weapon__

#include "Attachment.h"
class Weapon: public Attachment{
    friend class SpaceCraft;
public:
    virtual void fire(SpaceCraft& ms){};
    
    Weapon(std::string nam,float mass ,float momentOfInertia,float elasticity , sf::Vector2f centerOfMass, sf::Sprite sprite, DestroyEffect deathEffect , sf::Sound deathSound , std::vector<sf::Vector2f> LinePoints, long structint, unsigned int str, Material mat); //SolidObject(mass, moment of inertia, COM x, COM y, texture)  com=center of mass
    void loadAmmo();
    virtual std::string getType();
    Weapon(){};
protected:
    float _loadTime;
    float _loadTimer;
    
};


struct WeaponSlot               //Contains a position (the point on the spacecraft that a weapon can be mounted) and a weapon (What, if any weapon is mounted there)
{
public:
    Weapon * weapon;
    
    void setWeapon(Weapon& weap);
    sf::Vector2f getLocalPosition();
    
    WeaponSlot(sf::Vector2f pos);
private:
    sf::Vector2f _localPosition;
};
#endif /* defined(__SpaceGame__Weapon__) */
