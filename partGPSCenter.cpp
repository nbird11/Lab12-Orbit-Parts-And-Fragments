/******************************************************************************
 * Source File:
 *    GPSCenter
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS center part.
 *****************************************************************************/

#include "partGPSCenter.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void GPSCenter::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void GPSCenter::draw(ogstream& gout)
{
   gout.drawGPSCenter(pos, direction.getRadians());
}
