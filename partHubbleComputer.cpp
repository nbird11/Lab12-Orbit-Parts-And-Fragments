/******************************************************************************
 * Source File:
 *    Hubble Computer
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Hubble Computer.
 *****************************************************************************/

#include "fragment.h"
#include "partHubbleComputer.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

void HubbleComputer::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void HubbleComputer::draw(ogstream& gout)
{
   gout.drawHubbleComputer(pos, direction.getRadians());
}
