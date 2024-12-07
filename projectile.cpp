/***********************************************************************
 * Source File:
 *    Projectile
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    Projectile fired from the ship
 ************************************************************************/

#include "angle.h"
#include "position.h"
#include "projectile.h"
#include "satellite.h"
#include "uiDraw.h"
#include "velocity.h"
#include <cmath>
#include <vector>

//Projectile::Projectile(const Position& pos, const Velocity& vel, const Angle& direction) : Satellite(pos, vel)
//{
//   this->radius = 1;
//   this->age = 70;
//   this->direction = direction;
//   this->velocity.set(this->direction, this->velocity.getSpeed() + 9000.0);  // TODO: This is accurate to the description, but looks too fast.
//   this->pos.addPixels(19, this->direction.getRadians());  // TODO: 19px is accurate to the description
//}

Projectile::Projectile(const Satellite& rhs) : Satellite(rhs)
{
   this->radius = 1;
   this->age = 70;
   // this->velocity.set(this->direction, this->velocity.getSpeed() + 9000.0);  // TODO: This is accurate to the description, but looks too fast.
   this->velocity.setDX(this->velocity.getDX() + (9000.0 * sin(this->direction.getRadians())));  // TODO: This is accurate to the description, but looks too fast.
   this->velocity.setDY(this->velocity.getDY() + (9000.0 * cos(this->direction.getRadians())));  // TODO: This is accurate to the description, but looks too fast.
   // this->velocity.set(this->direction, this->velocity.getSpeed() + 9000.0);  // TODO: This is accurate to the description, but looks too fast.

   double speed = this->velocity.getSpeed();

   this->pos.addPixels(19, this->direction.getRadians());  // TODO: 19px is accurate to the description
}

void Projectile::destroy(std::vector<Satellite*>& satellites)
{

}

void Projectile::draw(ogstream& gout)
{
   gout.drawProjectile(pos);
}
