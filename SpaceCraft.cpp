//
//  SpaceCraft.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "SpaceCraft.h"

//Controls
void SpaceCraft::setForwardThrusters(bool on){
    _tForwardOn = on;
}
void SpaceCraft::setRetroThrusters(bool on){
    _tBackwardOn = on;
}
void SpaceCraft::setClockwiseThrusters(bool on){
    _tRotPosOn = on;
}
void SpaceCraft::setAnticlockwiseThrusters(bool on){
    _tRotNegOn = on;
}
void SpaceCraft::setRightThrusters(bool on){
    _tRightOn = on;
}
void SpaceCraft::setLeftThrusters(bool on){
    _tLeftOn = on;
}

double SpaceCraft::getThrusterTorque(){
    return _thrustRotPos;
}
//end controls

 void SpaceCraft::update(){
     updatePosition();
     updateCollisionData();
     updateThrusters();
     updateStatus();
     targetWindow->draw(_sprite);
}

void SpaceCraft::updateThrusters(){
    _tFBimage.setPosition(_sprite.getPosition());
    _tFBimage.setRotation(_sprite.getRotation());
    _tPNimage.setPosition(_sprite.getPosition());
    _tPNimage.setRotation(_sprite.getRotation());
    _tRLimage.setPosition(_sprite.getPosition());
    _tRLimage.setRotation(_sprite.getRotation());
    if(_tForwardOn==true){
        applyNetForce(_thrustForward*cos(getRotation()*PI/180),_thrustForward*sin(getRotation()*PI/180));
        _tForwardOn=false;
        _tForSound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y, 0);
        if(_tForSoundOn==false){
            _tForSound.play();
            _tForSoundOn=true;
        }
        _textureY=1;
        _tFBimage.setTextureRect(sf::IntRect(_textureX*_size.x*2, _textureY*_size.y*2, _size.x*2, _size.y*2));
        targetWindow->draw(_tFBimage);
    }
    else if(_tBackwardOn==true){
        applyNetForce(-_thrustBackward*cos(getRotation()*PI/180), -_thrustBackward*sin(getRotation()*PI/180));
        _tBackwardOn=false;
        _tBacSound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y, 0);
        if(_tBacSoundOn==false){
            _tBacSound.play();
            _tBacSoundOn=true;
        }
        _textureY=2;
        _tFBimage.setTextureRect(sf::IntRect(_textureX*_size.x*2, _textureY*_size.y*2, _size.x*2, _size.y*2));
        targetWindow->draw(_tFBimage);
    }
    else{
        _tForSound.stop();              _tForSoundOn=false;
        _tBacSound.stop();              _tBacSoundOn=false;
        _textureY=0;
    }
    
    if(_tRotPosOn==true){
        applyTorque(_thrustRotPos);
        _tRotPosOn=false;
        _tRotPosSound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y, 0);
        if(_tRotPosSoundOn==false){
            _tRotPosSound.play();
            _tRotPosSoundOn=true;
        }
        _textureY=3;
        _tPNimage.setTextureRect(sf::IntRect(_textureX*_size.x*2, _textureY*_size.y*2, _size.x*2, _size.y*2));
        targetWindow->draw(_tPNimage);
    }
    else if(_tRotNegOn==true){
        applyTorque(-_thrustRotNeg);
        _tRotNegOn=false;
        _tRotNegSound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y, 0);
        if(_tRotNegSoundOn==false){
            _tRotNegSound.play();
            _tRotNegSoundOn=true;
        }
        _textureY=4;
        _tPNimage.setTextureRect(sf::IntRect(_textureX*_size.x*2, _textureY*_size.y*2, _size.x*2, _size.y*2));
        targetWindow->draw(_tPNimage);
    }
    else{
        _tRotPosSound.stop();        _tRotPosSoundOn=false;
        _tRotNegSound.stop();        _tRotNegSoundOn=false;
        _textureY=0;
    }
    
    if(_tRightOn==true){
        applyNetForce(_thrustRight * cos(getRotation() * PI/180 + PI/2), _thrustRight * sin(getRotation() * PI/180 + PI/2));
        _tRightOn=false;
        _tRightSound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y, 0);
        if(_tRightSoundOn==false){
            _tRightSound.play();
            _tRightSoundOn=true;
        }
        _textureY=5;
        _tRLimage.setTextureRect(sf::IntRect(_textureX * _size.x * 2, _textureY * _size.y * 2, _size.x * 2, _size.y * 2));
        targetWindow->draw(_tRLimage);
    }
    else if(_tLeftOn==true){
        applyNetForce(_thrustLeft * cos(getRotation() * PI/180 - PI/2),_thrustLeft * sin(getRotation() * PI/180 - PI/2));
        _tLeftOn=false;
        _tLeftSound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y, 0);
        if(_tLeftSoundOn==false){
            _tLeftSound.play();
            _tLeftSoundOn=true;
        }
        _textureY=6;
        _tRLimage.setTextureRect(sf::IntRect(_textureX*_size.x*2, _textureY*_size.y*2, _size.x*2, _size.y*2));
        targetWindow->draw(_tRLimage);
    }
    else{
        _tRightSound.stop();       _tRightSoundOn=false;
        _tLeftSound.stop();        _tLeftSoundOn=false;
        _textureY=0;
    }
    _flamecount += dt;
    if(_flamecount >= _flameswitch){
        _textureX++;
        if (_textureX*_size.x*2>= _FlameSheet.getSize().x)
            _textureX=0;
        _flamecount=0;
    }
}

SpaceCraft::SpaceCraft(std::string nam, float A,float B,float cR ,sf::Vector2f centOfMass, sf::Sprite sprite, DestroyEffect deathEffect , sf::Sound deathSound , sf::Texture& flametex, std::vector<sf::Vector2f> LinePoints , float thrustarray[6], sf::Sound thrustsoundarray[6], long structint, unsigned int str, Material mat) //SpaceCraft(mass, momentofinertia, COM x, COM y, main texture, Flamesheet, thrustarray)
//Flamsheet must consist of frames twice the size of the ship rectangle
{
    name=nam;
    _mass=A * massUnits;
    _momentOfInertia=B * momentOfInertiaUnits;
    _elasticity=cR;
    _size=sprite.getTexture()->getSize();
    _sprite=sprite;
    _sprite.setOrigin(centOfMass);
    _centerOfMass=_sprite.getOrigin();
    _tFBimage.setTexture(flametex);
    _tFBimage.setTextureRect(sf::IntRect(0,0,_size.x*2, _size.y*2));
    _tFBimage.setOrigin(centOfMass.x * 2, centOfMass.y * 2);
    _tPNimage.setTexture(flametex);
    _tPNimage.setTextureRect(sf::IntRect(0,0,_size.x * 2, _size.y * 2));
    _tPNimage.setOrigin(centOfMass.x * 2, centOfMass.y * 2);
    _tRLimage.setTexture(flametex);
    _tRLimage.setTextureRect(sf::IntRect(0,0,_size.x*2, _size.y*2));
    _tRLimage.setOrigin(centOfMass.x * 2, centOfMass.y * 2);
    _thrustForward=thrustarray[0] * forceUnits;               _tForSound=thrustsoundarray[0];
    _thrustBackward=thrustarray[1] * forceUnits;            _tBacSound=thrustsoundarray[1];
    _thrustRotPos=thrustarray[2] * torqueUnits;                _tRotPosSound=thrustsoundarray[2];
    _thrustRotNeg=thrustarray[3] * torqueUnits;                _tRotNegSound=thrustsoundarray[3];
    _thrustRight=thrustarray[4] * forceUnits;                   _tRightSound=thrustsoundarray[4];
    _thrustLeft=thrustarray[5] * forceUnits;                     _tLeftSound=thrustsoundarray[5];
    
    _destroyAnimation=deathEffect;
    _destroySound=deathSound;
    _material=&mat;
    
    _velocity=sf::Vector2f(0,0);
    _rotationalVelocity=0;
    
    _collisionLinePoints=LinePoints;
    
    _structuralIntegrity=structint * structuralIntegrityUnits;
    _maxStructuralIntegrity=structint * structuralIntegrityUnits;
    _structuralStrength=str * structuralIntegrityUnits;
    _power=0;
}
SpaceCraft::SpaceCraft()
{
}

