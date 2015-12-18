//
//  VisualEffectHandler.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "VisualEffectHandler.h"

void visualEffectHandler()
{
    for(auto i=VisualEffect::VEffectList.begin()+1 ; i!=VisualEffect::VEffectList.end() ;)
    {
        if((i)->update(*SolidObject::targetWindow))
            i++;
        else
            i=VisualEffect::VEffectList.erase(i);
    }
}