/******************************************************************************
 * Source File:
 *    Starlink Array
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Starlink Array.
 *****************************************************************************/

#include "partStarlinkArray.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void StarlinkArray::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void StarlinkArray::draw(ogstream& gout)
{
   gout.drawStarlinkArray(pos, direction.getRadians());
}
