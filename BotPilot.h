//
//  BotPilot.h
//  SpaceGame
//
//  Created by Jonathan Wood on 03/11/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__BotPilot__
#define __SpaceGame__BotPilot__
#include <deque>
#include <iostream>
#include "CalculateAngle.h"
#include "Bot.h"
#include "ModifiedSpaceCraft.h"

//Current Behavior:
//Must be manually given target
//If has target then thrusts forward
class BotPilot: public Bot{
public:
    void assignShip(ModifiedSpaceCraft * ship);
    void setTarget(SolidObject & target);
    virtual void update();
protected:
    std::deque<bool (BotPilot::*)()> taskList;
    void engageTarget();
    ModifiedSpaceCraft * _ship;
    SolidObject * _target;
    
    //Actions, interface with spaceCraft Controls for convinience
    void thrustClockwise();
    void thrustAnticlockwise();
    
    //tasks, return true when complete
    bool rotateToGoal();
    bool cancelRotationalVelocity();
    
    double _rotateGoal;
    double _shipAngularAcceleration;
};
#endif /* defined(__SpaceGame__BotPilot__) */
