//
//  VisualEffect.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "VisualEffect.h"
std::vector<VisualEffect> VisualEffect::VEffectList {};

bool VisualEffect::update(sf::RenderWindow& wind){
    _counter+=dt;
    if(_counter>=_frameSwitch){
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


void VisualEffect::playEffect(sf::Vector2f pos){
    setPosition(pos);
    VEffectList.push_back(*this);
};


VisualEffect::VisualEffect(sf::Texture& sheet, double fs){
    _counter=0;
    _activeFrame=0;
    _frameSwitch=fs;
    _sprite.setTexture(sheet);
}


VisualEffect::VisualEffect(unsigned int frameNumX, unsigned int frameNumY, sf::Texture& sheet, double fs){
    _counter=0;
    _activeFrame=0;
    _frameSwitch=fs;
    _sprite.setTexture(sheet);
    
    int frameWidth=sheet.getSize().x/frameNumX;
    int frameHeight=sheet.getSize().y/frameNumY;
    for(int j=0 ; j<frameNumX ; j++)
    {
        for(int i=0 ; i<frameNumY ; i++)
        {
            addFrame(sf::IntRect(i*frameWidth, j*frameHeight, frameWidth, frameHeight));
        }
    }
}
    
VisualEffect::VisualEffect(){};


