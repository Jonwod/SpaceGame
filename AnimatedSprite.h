//
//  AnimatedSprite.h
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__AnimatedSprite__
#define __SpaceGame__AnimatedSprite__
#include <SFML/Graphics.hpp>

class AnimatedSprite
{
public:
    static double dt;
    void addFrame(sf::IntRect rect);
    void update(sf::RenderWindow& wind);
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
    AnimatedSprite(sf::Texture& sheet, double fs);
    AnimatedSprite(unsigned int frameNumX, unsigned int frameNumY, sf::Texture& sheet, double fs);
    AnimatedSprite();
protected:
    std::vector<sf::IntRect> _frames;
    int _activeFrame;
    int _numberOfFrames;
    double _frameSwitch;     //Switches every frameSwitch seconds
    double _counter;
    sf::Sprite _sprite;
};
#endif /* defined(__SpaceGame__AnimatedSprite__) */
