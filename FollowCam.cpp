//
//  FollowCam.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 08/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "FollowCam.h"
void cameraUpdate(sf::Vector2i screenSize,sf::View& view ,SolidObject& playship)  //Takes the window,  main view and the players ship. ship must start at center of view.
{
    float ix, iy;
    float niltopiX, niltopiY;
    float q = 0.2;  //Speed of camera goal adjust
    float Q = 1.0; //Speed of camera goal follow adjust
    static float offsetX, offsetY;
    niltopiX = fabs(((playship.getVelocity().x*q)/(screenSize.x*0.3))*PI);
    niltopiY = fabs(((playship.getVelocity().y*q)/(screenSize.y*0.3))*PI);
    
    if(playship.getVelocity().x*q <= screenSize.x*0.3 && playship.getVelocity().x*q >= -screenSize.x*0.3)
        ix = (playship.getVelocity().x*q)*((cos(niltopiX+PI)+1)/2);
    else
        if(playship.getVelocity().x>0)
            ix = screenSize.x*0.3;
        else
            ix = -screenSize.x*0.3;
    if(playship.getVelocity().y*q <= screenSize.y*0.3 && playship.getVelocity().y*q >= -screenSize.y*0.3)
        iy = (playship.getVelocity().y*q)*((cos(niltopiY + PI) + 1)/2);
    else
        if(playship.getVelocity().y > 0)
            iy = screenSize.y*0.3;
        else
            iy = -screenSize.y*0.3;
    
    if(offsetX<(ix-1))
        offsetX+=Q;
    if(offsetX>(ix+1))
        offsetX-=Q;
    if(offsetY<(iy-1))
        offsetY+=Q;
    if(offsetY>(iy+1))
        offsetY-=Q;
    view.setCenter(playship.getPosition().x+offsetX, playship.getPosition().y+offsetY);
    sf::Listener::setPosition(playship.getPosition().x, playship.getPosition().y, 20);
    sf::Listener::setGlobalVolume(100);
    SolidObject::targetWindow->setView(view);
}