//
//  AI.h
//  SpaceGame
//
//  Created by Jonathan Wood on 03/11/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__AI__
#define __SpaceGame__AI__
#include <vector>

class Bot{
public:
    static std::vector<Bot*> BotList;
    virtual void update(){};
};
#endif /* defined(__SpaceGame__AI__) */
