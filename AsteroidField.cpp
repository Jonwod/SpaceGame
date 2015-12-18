//
//  AsteroidField.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 12/11/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "AsteroidField.h"

AsteroidField::AsteroidField(SolidObject asteroidTemplate, sf::IntRect area){
    int numberOfAsteroids = _density * ((area.width/1000) * (area.height/1000));
    for(int i = 0 ; i < numberOfAsteroids ; ++i){
        SolidObject * pAst = new SolidObject;
        *pAst = asteroidTemplate;
        bool cont = true;
        unsigned int seed = (unsigned)time(0);
        while(cont){
            int posX =  getRandomIntInRange(area.left, area.left + area.width);
            int posY = getRandomIntInRange(area.top, area.top + area.height);
            seed = posX;
            pAst->setPosition(posX, posY);
            cont = false;
            for(i = 0 ; i < SolidObject::ObList.size() ; ++i){
                if( pAst->getSprite().getGlobalBounds().intersects(SolidObject::ObList[i]->getSprite().getGlobalBounds() )){
                    cont  = true;
                    break;
                }
            }
        }
        SolidObject::ObList.push_back(pAst);
    }
}