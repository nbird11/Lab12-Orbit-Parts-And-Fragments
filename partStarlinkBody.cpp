/******************************************************************************
 * Source File:
 *    Starlink Body
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Starlink Body.
 *****************************************************************************/

#include "fragment.h"
#include "partStarlinkBody.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

void StarlinkBody::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void StarlinkBody::draw(ogstream& gout)
{
   gout.drawStarlinkBody(pos, direction.getRadians());
}
