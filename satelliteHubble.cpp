/******************************************************************************
 * Source File:
 *    Hubble
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The unbroken Hubble derived class
 *****************************************************************************/

#include "partHubbleComputer.h"
#include "partHubbleLeft.h"
#include "partHubbleRight.h"
#include "partHubbleTelescope.h"
#include "satellite.h"
#include "satelliteHubble.h"
#include "uiDraw.h"
#include <vector>

/******************************************************************************
 * Hubble : DRAW
 *  use the passed ogstream to draw itself
 *****************************************************************************/
void Hubble::draw(ogstream& gout)
{
   gout.drawHubble(pos, direction.getDegrees());
}

void Hubble::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new HubbleTelescope(pos, velocity));
   satellites.push_back(new HubbleLeft(pos, velocity));
   satellites.push_back(new HubbleRight(pos, velocity));
   satellites.push_back(new HubbleComputer(pos, velocity));
}
