//
//  ModifiedSpaceCraft.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "ModifiedSpaceCraft.h"

//controls
void ModifiedSpaceCraft::fireAllWeapons(){
    for(int i = 0 ; i < _weaponSlots.size() ; ++i){
        if(_weaponSlots[i]->weapon != 0)
        {
            _weaponSlots[i]->weapon->fire(*this);
        }
    }
}

//end controls

void ModifiedSpaceCraft::attachWeapon(Weapon& weap ,int slot){
    _weaponSlots[slot]->setWeapon(weap);
    _weaponSlots[slot]->weapon->SetMotherShip(*this);
    _mass += weap.getMass();
    _momentOfInertia += weap.getMass() * magnitude(_weaponSlots[slot]->getLocalPosition());
}

void ModifiedSpaceCraft::updateWeapons(){
    for(int i=0 ; i<_weaponSlots.size() ; i++)
    {
        if(_weaponSlots[i]->weapon!=NULL)
        {
            _weaponSlots[i]->weapon->loadAmmo();
            _weaponSlots[i]->weapon->setPosition(getPixelGlobalPosition(*this, _weaponSlots[i]->getLocalPosition()));
            _weaponSlots[i]->weapon->setRotation(getRotation());
            targetWindow->draw(_weaponSlots[i]->weapon->getSprite());
        }
    }
}

ModifiedSpaceCraft::ModifiedSpaceCraft(std::string nam, float mass,float momentOfInertia,float elasticity ,sf::Vector2f centerOfMass, sf::Sprite sprite, DestroyEffect deathEffect , sf::Sound deathSound ,sf::Texture& flametex, std::vector<sf::Vector2f> LinePoints , float thrustarray[6], sf::Sound thrustsoundarray[6], std::vector<WeaponSlot*> weapSlots, long structint, unsigned int str, Material mat) //SpaceCraft(mass, momentofinertia, COM x, COM y, main texture, Flamesheet, thrustarray)
//Flamsheet must consist of frames twice the size of the ship rectangle
{
    name=nam;
    _mass=mass * massUnits;
    _momentOfInertia=momentOfInertia * momentOfInertiaUnits;
    _elasticity=elasticity;
    _size=sprite.getTexture()->getSize();
    _sprite=sprite;
    _sprite.setOrigin(centerOfMass);
    _centerOfMass=_sprite.getOrigin();
    _tFBimage.setTexture(flametex);
    _tFBimage.setTextureRect(sf::IntRect(0,0,_size.x*2, _size.y*2));
    _tFBimage.setOrigin(centerOfMass.x * 2, centerOfMass.y * 2);
    _tPNimage.setTexture(flametex);
    _tPNimage.setTextureRect(sf::IntRect(0,0,_size.x*2, _size.y*2));
    _tPNimage.setOrigin(centerOfMass.x * 2, centerOfMass.y * 2);
    _tRLimage.setTexture(flametex);
    _tRLimage.setTextureRect(sf::IntRect(0,0,_size.x*2, _size.y*2));
    _tRLimage.setOrigin(centerOfMass.x * 2, centerOfMass.y * 2);
    _thrustForward=thrustarray[0] * forceUnits;               _tForSound=thrustsoundarray[0];
    _thrustBackward=thrustarray[1] * forceUnits;            _tBacSound=thrustsoundarray[1];
    _thrustRotPos=thrustarray[2] * torqueUnits;                _tRotPosSound=thrustsoundarray[2];
    _thrustRotNeg=thrustarray[3] * torqueUnits;                _tRotNegSound=thrustsoundarray[3];
    _thrustRight=thrustarray[4] * forceUnits;                   _tRightSound=thrustsoundarray[4];
    _thrustLeft=thrustarray[5] * forceUnits;                     _tLeftSound=thrustsoundarray[5];
    _velocity=sf::Vector2f(0,0);
    _rotationalVelocity=0;
    
    _collisionLinePoints=LinePoints;
    
    _destroyAnimation=deathEffect;
    _destroySound=deathSound;
    _material=&mat;
    
    _weaponSlots=weapSlots;
    _structuralIntegrity=structint * structuralIntegrityUnits;
    _maxStructuralIntegrity=_structuralIntegrity;
    _structuralStrength=str * structuralStrengthUnits;
    _power=0;
}

ModifiedSpaceCraft::ModifiedSpaceCraft(){}

void ModifiedSpaceCraft::update(){
    updatePosition();
    updateStatus();
    updateCollisionData();
    updateThrusters();
    updateWeapons();
    targetWindow->draw(getSprite());
}
