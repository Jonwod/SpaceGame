//
//  PlayerSpaceCraft.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "PlayerSpaceCraft.h"
void PlayerSpaceCraft::getInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            _tForwardOn=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            _tBackwardOn=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            _tRotNegOn=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            _tRotPosOn=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            _tRightOn=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            _tLeftOn=true;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            if(_keyIreset==true)
                _weaponSlots[0]->weapon->fire(*this);
            _keyIreset=false;
        }
        else
            _keyIreset=true;
        
    }
    
 void PlayerSpaceCraft::update()
    {
        updatePosition();
        updateStatus();
        updateCollisionData();
        updateThrusters();
        updateWeapons();
        targetWindow->draw(getSprite());
    }
PlayerSpaceCraft::PlayerSpaceCraft(std::string nam, float A,float B,float cR ,sf::Vector2f COM, sf::Sprite sprite, DestroyEffect deathEffect , sf::Sound deathSound , sf::Texture& flametex, std::vector<sf::Vector2f> LinePoints , float thrustarray[6], sf::Sound thrustsoundarray[6], std::vector<WeaponSlot*> weapSlots, long structint, unsigned int str, Material mat) //SpaceCraft(mass, momentofinertia, COM x, COM y, main texture, Flamesheet, thrustarray)
    //Flamsheet must consist of frames twice the size of the ship rectangle
    {
        name=nam;
        _mass=A * massUnits;
        _momentOfInertia=B * momentOfInertiaUnits;
        _elasticity=cR;
        _size=sprite.getTexture()->getSize();
        _sprite=sprite;
        _sprite.setOrigin(COM);
        _centerOfMass=_sprite.getOrigin();
        _tFBimage.setTexture(flametex);
        _tFBimage.setTextureRect(sf::IntRect(0,0,_size.x*2, _size.y*2));
        _tFBimage.setOrigin(COM.x * 2, COM.y * 2);
        _tPNimage.setTexture(flametex);
        _tPNimage.setTextureRect(sf::IntRect(0,0,_size.x*2, _size.y*2));
        _tPNimage.setOrigin(COM.x * 2, COM.y * 2);
        _tRLimage.setTexture(flametex);
        _tRLimage.setTextureRect(sf::IntRect(0,0,_size.x*2, _size.y*2));
        _tRLimage.setOrigin(COM.x *2 , COM.y * 2);
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
    
PlayerSpaceCraft::PlayerSpaceCraft(){}
