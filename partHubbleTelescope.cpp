/***********************************************************************
 * Source File:
 *    Hubble Telescope
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Hubble Telescope.
 ************************************************************************/

#include "partHubbleTelescope.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void HubbleTelescope::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void HubbleTelescope::draw(ogstream& gout)
{
   gout.drawHubbleTelescope(pos, direction.getRadians());
}
