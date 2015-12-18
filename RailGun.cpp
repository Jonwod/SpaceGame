//
//  RailGun.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "RailGun.h"
#include <iostream>


void RailGun::setAmmo(Slug amo){
    _ammo=amo;
}

float RailGun::getLength(){
    return _length;
}

 std::string RailGun::getType(){
    return "RailGun";
}

void RailGun::fire(SpaceCraft& ms){
    if(_loadTimer >= _loadTime){
        Slug *prjctl=new Slug(_ammo);
        sf::Vector2f globalExitPoint = getPixelGlobalPosition( *this, _exitPoint);
        float exitV=sqrt( 2 * _length * (_force/_ammo.getMass()));
        prjctl->setRotation(getRotation());
        prjctl->setPosition(globalExitPoint);
        prjctl->setVelocity((cos(getRotation() * PI/180)) * exitV + getVelocity().x + ms.getVelocity().x,
                            (sin(getRotation() * PI/180))*exitV+getVelocity().y+ms.getVelocity().y);
        SolidObject::ObList.push_back(prjctl);
        ms.setVelocity(ms.getVelocity().x - ((cos(getRotation() * PI/180)) * exitV * _ammo.getMass())/ms.getMass(),
                       ms.getVelocity().y - ((sin(getRotation() * PI/180)) * exitV * _ammo.getMass())/ms.getMass());
        _fireSound.setPosition(globalExitPoint.x, globalExitPoint.y, 0);
        _fireSound.play();
        _loadTimer = 0;
    }
}

RailGun::RailGun(std::string nam, float A,float B,float Cr, sf::Vector2f centOfMass, sf::Sprite sprite, DestroyEffect deathEffect ,std::vector<sf::Vector2f> LinePoints, float len, float F, sf::Vector2f exit, long structint, unsigned int str, sf::Sound shotSound, Material mat, float loadTime)
{
    _mass = A * massUnits;
    _momentOfInertia = B * momentOfInertiaUnits;
    _elasticity = Cr;
    _sprite = sprite;
    _sprite.setOrigin(centOfMass);
    _centerOfMass = _sprite.getOrigin();
    _velocity = sf::Vector2f(0,0);
    _rotationalVelocity = 0;
    _size = _sprite.getTexture()->getSize();
    _collisionLinePoints=LinePoints;
    name=nam;
    _length=len;
    _force=F * forceUnits;
    _exitPoint=exit;
    _structuralIntegrity = structint * structuralIntegrityUnits;
    _structuralStrength=str * structuralStrengthUnits;
    _fireSound=shotSound;
    _destroyAnimation=deathEffect;
    _material = &mat;
    
    _loadTime = loadTime;
}

RailGun::RailGun(){};