//
//  HUD.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "HUD.h"


HUDsprite::HUDsprite(sf::Sprite& sprt, sf::Vector2f rat){
    sprite=sprt;
    posRatio=rat;
}

HUDsprite::HUDsprite(sf::Sprite& sprt, float ratx, float raty){
    sprite=sprt;
    posRatio=sf::Vector2f(ratx, raty);
}
HUDsprite::HUDsprite(){};


HUDtext::HUDtext(sf::Text& txt, sf::Vector2f rat){
    text=txt;
    posRatio=rat;
}

HUDtext::HUDtext(sf::Text& txt, float ratx, float raty){
    text=txt;
    posRatio=sf::Vector2f(ratx, raty);
}

HUDtext::HUDtext(){}


void HUD::update(sf::RenderWindow& wind ,const sf::View& view, sf::Vector2i screenSize){
    for(int i=0 ; i<sprites.size() ; i++){
        sf::Vector2f topLeft=view.getCenter()-multiply(sf::Vector2f(screenSize.x, screenSize.y), 0.5f);
        sprites[i].sprite.setPosition(topLeft+sf::Vector2f(sprites[i].posRatio.x*screenSize.x, sprites[i].posRatio.y*screenSize.y));
        wind.draw(sprites[i].sprite);
    }
    for(int i=0 ; i<words.size() ; i++){
        sf::Vector2f topLeft=view.getCenter()-multiply(sf::Vector2f(screenSize.x, screenSize.y), 0.5f);
        words[i].text.setPosition(topLeft+sf::Vector2f(words[i].posRatio.x*screenSize.x, words[i].posRatio.y*screenSize.y));
        wind.draw(words[i].text);
    }
}

void HUD::addSprite(sf::Sprite& sprite, sf::Vector2f posRat){
    HUDsprite hudsprite (sprite, posRat);
    sprites.push_back(hudsprite);
}

void HUD::addText(sf::Text& text, sf::Vector2f posRat){
    HUDtext hudtext (text, posRat);
    words.push_back(hudtext);
}

void HUD::addSprite(sf::Sprite& sprite, float posRatx, float posRaty){
    HUDsprite hudsprite (sprite, posRatx, posRaty);
    sprites.push_back(hudsprite);
}

void HUD::addText(sf::Text& text, float posRatx, float posRaty){
    HUDtext hudtext(text, posRatx, posRaty);
    words.push_back(hudtext);
}


