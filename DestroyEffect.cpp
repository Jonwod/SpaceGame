//
//  DestroyEffect.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "DestroyEffect.h"

bool DestroyEffect::update(sf::RenderWindow& wind){
    _sprite.move(_velocity.x*dt, _velocity.y*dt);
    _counter+=dt;
    if(_counter>=_frameSwitch)
    {
        if(_activeFrame+1<_frames.size())
            _activeFrame+=1;
        else
            return false;
        _counter=0;
    }
    _sprite.setTextureRect(_frames[_activeFrame]);
    wind.draw(_sprite);
    return true;
}


void DestroyEffect::playEffect(sf::Vector2f pos, sf::Vector2f vel){
    setPosition(pos);
    _velocity=vel;
    VEffectList.push_back(*this);
};


DestroyEffect::DestroyEffect(unsigned int frameNumX, unsigned int frameNumY, sf::Texture& sheet, double fs){
    _counter=0;
    _activeFrame=0;
    _frameSwitch=fs;
    _sprite.setTexture(sheet);
    
    int frameWidth=sheet.getSize().x/frameNumX;
    int frameHeight=sheet.getSize().y/frameNumY;
    _sprite.setOrigin(frameWidth/2, frameHeight/2);
    for(int j=0 ; j<frameNumX ; j++){
        for(int i=0 ; i<frameNumY ; i++){
            addFrame(sf::IntRect(i*frameWidth, j*frameHeight, frameWidth, frameHeight));
        }
    }
}


DestroyEffect::DestroyEffect(){};