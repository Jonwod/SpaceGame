//
//  Attachment.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 09/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "Attachment.h"

SpaceCraft Attachment::GetMotherShip()
{
    return _motherShip;
}
void Attachment::SetMotherShip(SpaceCraft& ms)
{
    _motherShip=ms;
}
Attachment::Attachment()
{
}
