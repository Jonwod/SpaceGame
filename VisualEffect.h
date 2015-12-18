//
//  VisualEffect.h
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__VisualEffect__
#define __SpaceGame__VisualEffect__

#include "AnimatedSprite.h"

class VisualEffect: public AnimatedSprite{
protected:
public:
    static std::vector<VisualEffect> VEffectList;
    virtual bool update(sf::RenderWindow& wind);
    virtual void playEffect(sf::Vector2f pos);
    VisualEffect(sf::Texture& sheet, double fs);
    VisualEffect(unsigned int frameNumX, unsigned int frameNumY, sf::Texture& sheet, double fs);
    VisualEffect();
};


#endif /* defined(__SpaceGame__VisualEffect__) */
