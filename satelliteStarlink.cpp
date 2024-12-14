/******************************************************************************
 * Source File:
 *    Starlink
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Starlink satellite which inherits from the base Satellite
 *****************************************************************************/

#include "fragment.h"
#include "partStarlinkArray.h"
#include "partStarlinkBody.h"
#include "satellite.h"
#include "satelliteStarlink.h"
#include "uiDraw.h"
#include <vector>

/******************************************************************************
 * Starlink : DRAW
 *  use the passed ogstream to draw itself
 *****************************************************************************/
void Starlink::draw(ogstream& gout)
{
   gout.drawStarlink(pos, direction.getDegrees());
}

void Starlink::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new StarlinkBody(pos, velocity));
   satellites.push_back(new StarlinkArray(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}
