//
//  Slug.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "Slug.h"
#include <iostream>

Slug::Slug(std::string nam ,float A,float B,float Cr, sf::Vector2f centerOfMass, sf::Sprite sprite,DestroyEffect deathEffect , sf::Sound deathSound, std::vector<sf::Vector2f> LinePoints, long structint, unsigned int str, Material mat) //SolidObject(mass, moment of inertia, COM x, COM y, texture)  com=center of mass
{
    _mass=A * massUnits;
    _momentOfInertia=B * momentOfInertiaUnits;
    _elasticity=Cr;
    _sprite=sprite;
    _destroySound=deathSound;
    _destroyAnimation = deathEffect;
    _sprite.setOrigin(centerOfMass);
    _centerOfMass = _sprite.getOrigin();
    _velocity=sf::Vector2f(0,0);
    _rotationalVelocity=0;
    _size=_sprite.getTexture()->getSize();
    _collisionLinePoints=LinePoints;
    name=nam;
    _structuralIntegrity=structint * structuralIntegrityUnits;
    _maxStructuralIntegrity=_structuralIntegrity;
    _structuralStrength=str * structuralStrengthUnits;
    _lifeTimer=4;
    _material=&mat;
}

void Slug::update(){
    _lifeTimer-=SolidObject::dt;
    updateCollisionData();
    updateStatus();

    _sprite.move(_velocity.x*dt, _velocity.y*dt);
    _sprite.rotate(_rotationalVelocity*dt);
    SolidObject::targetWindow->draw(_sprite);
}

void Slug::updateStatus(){
    if(getStructuralIntegrity()<=0 || _lifeTimer<=0){
        destroy();
    }
}
Slug::Slug(){};




