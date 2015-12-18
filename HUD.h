//
//  HUD.h
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__HUD__
#define __SpaceGame__HUD__

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "VectorMaths.h"

struct HUDsprite{
    sf::Vector2f posRatio;
    sf::Sprite sprite;
    HUDsprite(sf::Sprite& sprt, sf::Vector2f rat);
    HUDsprite(sf::Sprite& sprt, float ratx, float raty);
    HUDsprite();
};

struct HUDtext{
    sf::Vector2f posRatio;
    sf::Text text;
    HUDtext(sf::Text& txt, sf::Vector2f rat);
    HUDtext(sf::Text& txt, float ratx, float raty);
    HUDtext();
};


class HUD{
protected:
    std::vector<HUDsprite> sprites;
    std::vector<HUDtext> words;
public:
    void update(sf::RenderWindow& wind ,const sf::View& view, sf::Vector2i screenSize);
    void addSprite(sf::Sprite& sprite, sf::Vector2f posRat);
    void addText(sf::Text& text, sf::Vector2f posRat);
    void addSprite(sf::Sprite& sprite, float posRatx, float posRaty);
    void addText(sf::Text& text, float posRatx, float posRaty);
};

#endif /* defined(__SpaceGame__HUD__) */
