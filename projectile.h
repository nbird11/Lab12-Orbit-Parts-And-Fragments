/******************************************************************************
 * Header File:
 *    Projectile
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Projectile fired from the ship
 *****************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestProjectile;
class TestShip;

class Projectile : public Satellite
{
public:
   friend TestProjectile;
   friend TestShip;

   Projectile() : Satellite(), age(70) { radius = 1.0; }
   Projectile(const Satellite& rhs);

   void move(double time) override
   {
      Satellite::move(time);
      age--;
      if (age == 0) kill();
   }
   void destroy(std::vector<Satellite*>& satellites);
   void draw(ogstream& gout);

private:
   int age;
};
