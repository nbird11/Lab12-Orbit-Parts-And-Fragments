/******************************************************************************
 * Source File:
 *    Sputnik
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The unbroken Sputnik derived class
 *****************************************************************************/

#include "fragment.h"
#include "satellite.h"
#include "satelliteSputnik.h"
#include "uiDraw.h"
#include <vector>

/******************************************************************************
 * Sputnik : DRAW
 *  use the passed ogstream to draw itself
 *****************************************************************************/
void Sputnik::draw(ogstream& gout)
{
   gout.drawSputnik(pos, direction.getDegrees());
}

void Sputnik::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}
