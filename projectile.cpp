/***********************************************************************
 * Source File:
 *    Projectile
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    Projectile fired from the ship
 ************************************************************************/

#include "projectile.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

void Projectile::destroy(std::vector<Satellite*>& satellites)
{

}

void Projectile::draw(ogstream& gout)
{
   gout.drawProjectile(pos);
}
