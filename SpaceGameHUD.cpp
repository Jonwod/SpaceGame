//
//  SpaceGameHUD.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 13/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "SpaceGameHUD.h"

SpaceGameHUD::SpaceGameHUD(const PlayerSpaceCraft& ps){
        static sf::Font arial;
        arial.loadFromFile("/Users/jonathanwood/Documents/Programming/C ++/Assets/Arial.ttf");

        playShip=ps;
        
        sf::Text healthPercentText ("100%" , arial, 30);
        healthPercentText.setColor(sf::Color(147, 23, 23, 198));
        structIntPercentText=HUDtext(healthPercentText, 0.2, 0.025);
        
        sf::Text speedmagText("0m/s", arial, 30);
        speedmagText.setColor(sf::Color(147, 23, 23, 198));
        vmagText=HUDtext(speedmagText, 0.11, 0.858);
        
        sf::Text speedXText("0m/s", arial, 20);
        speedXText.setColor(sf::Color(147, 23, 23, 198));
        vxText=HUDtext(speedXText, 0.123, 0.9);
        
        sf::Text speedYText("0m/s", arial, 20);
        speedYText.setColor(sf::Color(147, 23, 23, 198));
        vyText=HUDtext(speedYText, 0.123, 0.937);
        
        static sf::Texture hudLabelsTexture;
        hudLabelsTexture.loadFromFile("/Users/jonathanwood/Documents/Programming/C ++/Assets/hudLabels.png");

        sf::Sprite hudLabelsSprite;
        hudLabelsSprite.setTexture(hudLabelsTexture);
        addSprite(hudLabelsSprite, 0, 0);
}

void SpaceGameHUD::update(const sf::View& view, sf::Vector2i screenSize,PlayerSpaceCraft& ps){
    sf::Vector2f topLeft=view.getCenter()-multiply(sf::Vector2f(screenSize.x, screenSize.y), 0.5f);
        float currentIntegrity=ps.getStructuralIntegrity();
        float maxIntegrity=ps.getMaxStructuralIntegrity();
        float healthpercent=float((currentIntegrity/maxIntegrity)*100);
        structIntPercentText.text.setString(std::to_string(healthpercent)+"%");
        structIntPercentText.text.setPosition(topLeft+sf::Vector2f(structIntPercentText.posRatio.x*screenSize.x, structIntPercentText.posRatio.y*screenSize.y));
        SolidObject::targetWindow->draw(structIntPercentText.text);
        
        vmagText.text.setString(std::to_string(magnitude(ps.getVelocity()))+"m/s");
        vmagText.text.setPosition(topLeft+sf::Vector2f(vmagText.posRatio.x*screenSize.x, vmagText.posRatio.y*screenSize.y));
        SolidObject::targetWindow->draw(vmagText.text);
        
        vxText.text.setString(std::to_string(ps.getVelocity().x)+"m/s");
        vxText.text.setPosition(topLeft+sf::Vector2f(vxText.posRatio.x*screenSize.x, vxText.posRatio.y*screenSize.y));
        SolidObject::targetWindow->draw(vxText.text);
        
        vyText.text.setString(std::to_string(-ps.getVelocity().y)+"m/s");
        vyText.text.setPosition(topLeft+sf::Vector2f(vyText.posRatio.x*screenSize.x, vyText.posRatio.y*screenSize.y));
        SolidObject::targetWindow->draw(vyText.text);
        
        for(int i=0 ; i<sprites.size() ; i++)
        {
            sprites[i].sprite.setPosition(topLeft+sf::Vector2f(sprites[i].posRatio.x*screenSize.x, sprites[i].posRatio.y*screenSize.y));
            SolidObject::targetWindow->draw(sprites[i].sprite);
        }
        for(int i=0 ; i<words.size() ; i++)
        {
            words[i].text.setPosition(topLeft+sf::Vector2f(words[i].posRatio.x*screenSize.x, words[i].posRatio.y*screenSize.y));
            SolidObject::targetWindow->draw(words[i].text);
        }
}

