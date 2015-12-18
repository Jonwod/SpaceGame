//
//  RandomNumberGeneration.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 12/11/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "RandomNumberGeneration.h"

int getRandomIntInRange(int n1, int n2){
    return  rand() % (n2-n1) +n1;
}