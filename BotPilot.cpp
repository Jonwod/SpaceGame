//
//  BotPilot.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 03/11/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "BotPilot.h"

void BotPilot::update(){
    if(_target != 0 && _target->isDestroyed())
        _target = 0;
    if(_target !=0 ){
        float errorMargin = 10.0;
        double bearingToTarget = calculateBearingFromAtoB(_ship->getPosition(), _target->getPosition());
        if(fabs(_ship->getRotation() - bearingToTarget) <= errorMargin){
            cancelRotationalVelocity();
            _ship->fireAllWeapons();
        }
    }
    
    if(taskList.size() > 0){
        if((this->*taskList[0])())
            taskList.pop_front();
    }
    else if(_target != 0){
        engageTarget();
        rotateToGoal();
    }
}

void BotPilot::thrustClockwise(){
    _ship->setClockwiseThrusters(true);
    _ship->setAnticlockwiseThrusters(false);
}
void BotPilot::thrustAnticlockwise(){
    _ship->setClockwiseThrusters(false);
    _ship->setAnticlockwiseThrusters(true);
}


bool BotPilot::rotateToGoal(){
    double clockwiseDegreesToGoal = _rotateGoal - _ship->getRotation();
    if(clockwiseDegreesToGoal > 180)
        clockwiseDegreesToGoal -= 360;
    else if(clockwiseDegreesToGoal < -180)
        clockwiseDegreesToGoal += 360;
    double errorMargin = 10.0;
    if(fabs(clockwiseDegreesToGoal) <= errorMargin)
        return true;
    
    if(_ship->getRotationalVelocity() == 0){
        if(clockwiseDegreesToGoal > 0)
            thrustClockwise();
        else if(clockwiseDegreesToGoal <0)
            thrustAnticlockwise();
    }
    double stopPointIfDecelerateNow;
    if(clockwiseDegreesToGoal > 0){
        stopPointIfDecelerateNow = - pow(_ship->getRotationalVelocity(), 2) / (2 * -_shipAngularAcceleration);
        if(stopPointIfDecelerateNow > (clockwiseDegreesToGoal - errorMargin))
            thrustAnticlockwise();                  //decelerate
        else if (stopPointIfDecelerateNow <( clockwiseDegreesToGoal - errorMargin))
            thrustClockwise();                          //accelerate
    }
    else{
        stopPointIfDecelerateNow = - pow(_ship->getRotationalVelocity(), 2) / (2 * _shipAngularAcceleration);
        if(stopPointIfDecelerateNow < (clockwiseDegreesToGoal + errorMargin))
            thrustClockwise();                          //decelerate
        else if(stopPointIfDecelerateNow > (_rotateGoal + errorMargin))
            thrustAnticlockwise();                  //accelerate
    }
    return false;
}


bool BotPilot::cancelRotationalVelocity(){
    float errorMargin = 2;
    bool completed = false;
    if(_ship->getRotationalVelocity() > errorMargin){
        _ship->setAnticlockwiseThrusters(true);
        _ship->setClockwiseThrusters(false);
    }
    else if(_ship->getRotationalVelocity() < -errorMargin){
        _ship->setClockwiseThrusters(true);
        _ship->setAnticlockwiseThrusters(false);
    }
    else
        completed = true;
    
    return completed;
}

void BotPilot::assignShip(ModifiedSpaceCraft * ship){
    _ship = ship;
    _shipAngularAcceleration = _ship->getThrusterTorque() / _ship->getMomentOfInertia();
}

void BotPilot::setTarget(SolidObject & target){
    _target = &target;
}

void BotPilot::engageTarget(){
    float errorMargin = 10.0;
    double bearingToTarget = calculateBearingFromAtoB(_ship->getPosition(), _target->getPosition());
    if(fabs(_ship->getRotation() - bearingToTarget) <= errorMargin){
        cancelRotationalVelocity();
     }
    else{
        _rotateGoal = bearingToTarget;
    }
}

