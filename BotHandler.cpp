//
//  AIhandler.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 03/11/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "BotHandler.h"

void BotHandler(){
    for(int i =0 ; i < Bot::BotList.size() ; ++i){
        Bot::BotList[i]->update();
    }
}