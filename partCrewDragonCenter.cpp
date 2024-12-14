/******************************************************************************
 * Source File:
 *    Crew Dragon Center
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    Center part of the crew dragon.
 *****************************************************************************/

#include "partCrewDragonCenter.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void CrewDragonCenter::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void CrewDragonCenter::draw(ogstream& gout)
{
   gout.drawCrewDragonCenter(pos, direction.getRadians());
}
