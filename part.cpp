/***********************************************************************
 * Source File:
 *    Part
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The base Part class for each type satellite for when it gets broken
 *    up.
 ************************************************************************/

#include "angle.h"
#include "part.h"
#include "position.h"
#include "satellite.h"
#include "uiDraw.h"
#include "velocity.h"

Part::Part(const Position& pos, const Velocity& vel)
   : Satellite(pos, vel)
{
   this->direction.setDegrees(random(0, 360));
   this->velocity.set(this->direction, this->velocity.getSpeed() + random(5000.0, 9000.0));
   this->pos.addPixels(4, this->direction.getRadians());
}
