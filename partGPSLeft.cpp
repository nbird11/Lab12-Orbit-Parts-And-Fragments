/******************************************************************************
 * Source File:
 *    GPSLeft
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS left part.
 *****************************************************************************/

#include "partGPSLeft.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>


void GPSLeft::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void GPSLeft::draw(ogstream& gout)
{
   gout.drawGPSLeft(pos, direction.getRadians());
}
