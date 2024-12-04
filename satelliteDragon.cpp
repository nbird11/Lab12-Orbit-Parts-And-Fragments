/***********************************************************************
 * Source File:
 *    Dragon
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The unbroken Dragon derived class
 ************************************************************************/

#include "fragment.h"
#include "partCrewDragonCenter.h"
#include "partCrewDragonLeft.h"
#include "partCrewDragonRight.h"
#include "satellite.h"
#include "satelliteDragon.h"
#include "uiDraw.h"
#include <vector>

/*********************************************
 * CrewDragon : DRAW
 *  use the passed ogstream to draw itself
 *********************************************/
void CrewDragon::draw(ogstream& gout)
{
   gout.drawCrewDragon(pos, direction.getDegrees());
}

void CrewDragon::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new CrewDragonCenter(pos, velocity));
   satellites.push_back(new CrewDragonLeft(pos, velocity));
   satellites.push_back(new CrewDragonRight(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}