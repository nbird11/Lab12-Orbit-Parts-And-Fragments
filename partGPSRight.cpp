/******************************************************************************
 * Source File:
 *    GPSRight
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS right part.
 *****************************************************************************/

#include "partGPSRight.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void GPSRight::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void GPSRight::draw(ogstream& gout)
{
   gout.drawGPSRight(pos, direction.getRadians());
}
