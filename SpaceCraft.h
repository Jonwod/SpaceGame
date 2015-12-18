//
//  SpaceCraft.h
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__SpaceCraft__
#define __SpaceGame__SpaceCraft__

#include <vector>
#include "SolidObject.h"
#define PI 3.14159265


class SpaceCraft: public SolidObject {
public:
    //Controls
    void setForwardThrusters(bool on);
    void setRetroThrusters(bool on);
    void setClockwiseThrusters(bool on);
    void setAnticlockwiseThrusters(bool on);
    void setLeftThrusters(bool on);
    void setRightThrusters(bool on);
    
    double getThrusterTorque();
    //end of controls
    
    virtual void update();
    void updateThrusters();
    SpaceCraft(std::string nam, float mass, float momentOfInertia,float elasticity ,sf::Vector2f centerOfMass
                      , sf::Sprite sprite, DestroyEffect deathEffect, sf::Sound deathSound ,
               sf::Texture& flametex, std::vector<sf::Vector2f> LinePoints , float thrustarray[6], sf::Sound thrustsoundarray[6], long structint, unsigned int str, Material mat);
    //Flamsheet must consist of frames twice the size of the ship rectangle
    SpaceCraft();
protected:
    double _flamecount=0.0;
    double _flameswitch=0.01;
    int _textureX=0;
    int _textureY=0;
    sf::Texture _FlameSheet;
    double _thrustForward;                bool _tForwardOn=false;       sf::Sound _tForSound;               bool _tForSoundOn=false;             sf::Sprite _tFBimage;
    double _thrustBackward;              bool _tBackwardOn=false;    sf::Sound _tBacSound;              bool _tBacSoundOn=false;
    double _thrustRotPos;                 bool _tRotPosOn=false;         sf::Sound _tRotPosSound;          bool _tRotPosSoundOn=false;       sf::Sprite _tPNimage;
    double _thrustRotNeg;                 bool _tRotNegOn=false;         sf::Sound _tRotNegSound;         bool _tRotNegSoundOn=false;
    double _thrustRight;                    bool _tRightOn=false;            sf::Sound _tRightSound;             bool _tRightSoundOn=false;           sf::Sprite _tRLimage;
    double _thrustLeft;                      bool _tLeftOn=false;              sf::Sound _tLeftSound;              bool _tLeftSoundOn=false;
    unsigned long int _power;        //Units: Kilo Watts
};

#endif /* defined(__SpaceGame__SpaceCraft__) */
