/***********************************************************************
 * Header File:
 *    Projectile
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Projectile fired from the ship
 ************************************************************************/

#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestProjectile;

class Projectile : public Satellite
{
public:
   friend TestProjectile;

    Projectile(const Position& pos, const Velocity& vel) : Satellite(pos, vel) { this->radius = 1; }

   void destroy(std::vector<Satellite*>& satellites);
   void draw(ogstream& gout);
};
