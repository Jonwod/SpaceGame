//
//  Material.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 02/10/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "Material.h"

void Material::playImpactSoundAt(sf::Vector2f point)
{
    impactSound.setPosition(point.x, point.y, 0);
    impactSound.play();
}
Material::Material(sf::Sound sound)
{
    impactSound=sound;
}