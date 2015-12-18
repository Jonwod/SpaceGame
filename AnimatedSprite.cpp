//
//  AnimatedSprite.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "AnimatedSprite.h"

double AnimatedSprite::dt=(1.0/60.0);

void AnimatedSprite::addFrame(sf::IntRect rect){
    _frames.push_back(rect);
}


void AnimatedSprite::update(sf::RenderWindow& wind){
    _counter+=dt;
    if(_counter>=_frameSwitch)
    {
        if(_activeFrame+1<_frames.size())
            _activeFrame+=1;
        else
            _activeFrame=0;
        _counter=0;
    }
    _sprite.setTextureRect(_frames[_activeFrame]);
    _sprite.setOrigin(_sprite.getTextureRect().width/2, _sprite.getTextureRect().height/2);
    wind.draw(_sprite);
}


void AnimatedSprite::setPosition(sf::Vector2f pos){
    _sprite.setPosition(pos);}


void AnimatedSprite::setPosition(float x, float y){
    _sprite.setPosition(x, y);
}


AnimatedSprite::AnimatedSprite(sf::Texture& sheet, double fs){
    _counter=0;
    _activeFrame=0;
    _frameSwitch=fs;
    _sprite.setTexture(sheet);
}


AnimatedSprite::AnimatedSprite(unsigned int frameNumX, unsigned int frameNumY, sf::Texture& sheet, double fs){
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


AnimatedSprite::AnimatedSprite(){};
