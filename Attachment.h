//
//  Attachment.h
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef __SpaceGame__Attachment__
#define __SpaceGame__Attachment__
#include "SpaceCraft.h"

class Attachment: public SolidObject{
public:
    SpaceCraft GetMotherShip();
    void SetMotherShip(SpaceCraft& ms);
    Attachment();
protected:
    friend class SpaceCraft;
    SpaceCraft _motherShip;
};

#endif /* defined(__SpaceGame__Attachment__) */
