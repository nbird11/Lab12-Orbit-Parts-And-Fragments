/***********************************************************************
 * Source File:
 *    Hubble Right
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The right part of the hubble satellite.
 ************************************************************************/

#include "partHubbleRight.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void HubbleRight::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void HubbleRight::draw(ogstream& gout)
{
   gout.drawHubbleRight(pos, direction.getRadians());
}
