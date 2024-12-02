/***********************************************************************
 * Source File:
 *    Crew Dragon Left
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    Left part of the crew dragon.
 ************************************************************************/

#include "partCrewDragonLeft.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void CrewDragonLeft::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void CrewDragonLeft::draw(ogstream& gout)
{
   gout.drawCrewDragonLeft(pos, direction.getRadians());
}
