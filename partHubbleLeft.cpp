/******************************************************************************
 * Source File:
 *    Hubble Left
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The left part of the hubble satellite.
 *****************************************************************************/

#include "partHubbleLeft.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void HubbleLeft::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void HubbleLeft::draw(ogstream& gout)
{
   gout.drawHubbleLeft(pos, direction.getRadians());
}
