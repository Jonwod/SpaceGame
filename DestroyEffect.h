//
//  DestroyEffect.h
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__DestroyEffect__
#define __SpaceGame__DestroyEffect__

#include "VisualEffect.h"

class DestroyEffect: public VisualEffect{
    sf::Vector2f _velocity;
public:
    bool update(sf::RenderWindow& wind);
    void playEffect(sf::Vector2f pos, sf::Vector2f vel);
    DestroyEffect(unsigned int frameNumX, unsigned int frameNumY, sf::Texture& sheet, double fs);
    DestroyEffect();
};


#endif /* defined(__SpaceGame__DestroyEffect__) */
