//
//  Weapon.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "Weapon.h"

Weapon::Weapon(std::string nam,float A,float B,float Cr , sf::Vector2f centerOfMass, sf::Sprite sprite, DestroyEffect deathEffect , sf::Sound deathSound , std::vector<sf::Vector2f> LinePoints, long structint, unsigned int str, Material mat)
{
    name = nam;
    _mass = A * massUnits;
    _momentOfInertia = B * momentOfInertiaUnits;
    _elasticity = Cr;
    _sprite = sprite;
    _sprite.setOrigin(centerOfMass.x, centerOfMass.y);
    _centerOfMass = _sprite.getOrigin();
    _velocity = sf::Vector2f(0,0);
    _rotationalVelocity = 0;
    _size = _sprite.getTexture()->getSize();
    _collisionLinePoints = LinePoints;
    _structuralIntegrity = structint * structuralIntegrityUnits;
    _maxStructuralIntegrity = _structuralIntegrity;
    _structuralStrength = str * structuralStrengthUnits;
    _destroyAnimation = deathEffect;
    _destroySound = deathSound;
    _material = &mat;
}

void Weapon::loadAmmo(){
    _loadTimer += SolidObject::dt;
}

std::string Weapon::getType(){
    return "Abstract weapon";
};

void WeaponSlot::setWeapon(Weapon & weap){
    weapon=&weap;
};

sf::Vector2f WeaponSlot::getLocalPosition(){
    return _localPosition;
};

WeaponSlot::WeaponSlot(sf::Vector2f pos){
    _localPosition=pos;
}

