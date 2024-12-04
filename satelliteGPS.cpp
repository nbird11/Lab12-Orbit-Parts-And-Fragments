/***********************************************************************
 * Source File:
 *    GPS
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS satellite which inherits from the base Satellite
 ************************************************************************/

#include "partGPSCenter.h"
#include "partGPSLeft.h"
#include "partGPSRight.h"
#include "satellite.h"
#include "satelliteGPS.h"
#include "fragment.h"
#include "uiDraw.h"
#include <vector>

/*********************************************
 * GPS : DRAW
 *  use the passed ogstream to draw itself
 *********************************************/
void GPS::draw(ogstream& gout)
{
   gout.drawGPS(pos, direction.getDegrees());
}

void GPS::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new GPSCenter(pos, velocity));
   satellites.push_back(new GPSLeft(pos, velocity));
   satellites.push_back(new GPSRight(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}
