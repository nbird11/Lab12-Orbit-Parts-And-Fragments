/******************************************************************************
 * Source File:
 *    Projectile
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    Projectile fired from the ship
 *****************************************************************************/

#include "angle.h"
#include "position.h"
#include "projectile.h"
#include "satellite.h"
#include "uiDraw.h"
#include "velocity.h"
#include <cmath>
#include <vector>

Projectile::Projectile(const Satellite& rhs) : Satellite(rhs)
{
   this->radius = 1;
   this->age = 70;
   // TODO: This is accurate to the description, but looks too fast.
   this->velocity.setDX(this->velocity.getDX() + 
      (9000.0 * sin(this->direction.getRadians())));
   // TODO: This is accurate to the description, but looks too fast.
   this->velocity.setDY(this->velocity.getDY() + 
      (9000.0 * cos(this->direction.getRadians())));

   //double speed = this->velocity.getSpeed();

   // TODO: 19px is accurate to the description
   this->pos.addPixels(19, this->direction.getRadians());
}

void Projectile::destroy(std::vector<Satellite*>& satellites)
{
}

void Projectile::draw(ogstream& gout)
{
   gout.drawProjectile(pos);
}
