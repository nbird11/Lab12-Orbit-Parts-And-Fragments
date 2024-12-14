/******************************************************************************
 * Source File:
 *    Crew Dragon Right
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    Right part of the crew dragon.
 *****************************************************************************/

#include "partCrewDragonRight.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void CrewDragonRight::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void CrewDragonRight::draw(ogstream& gout)
{
   gout.drawCrewDragonRight(pos, direction.getRadians());
}
