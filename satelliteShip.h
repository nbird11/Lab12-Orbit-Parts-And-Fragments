/******************************************************************************
 * Header File:
 *    Ship
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Ship controlled by the player
 *****************************************************************************/
#pragma once
#include "satellite.h"
#include "uiInteract.h"
#include <vector>

class Position;
class Velocity;
class ogstream;

class TestShip;

/******************************************************************************
 * Ship
 * The Starlink type derived from Satellite
 *****************************************************************************/
class Ship : public Satellite
{
public:
   friend TestShip;

   Ship();
   ~Ship() { }

   void input(const Interface* pUI);
   void setFiring() { firing = true; }
   bool isFiring() const { return firing; }
   void fire(std::vector<Satellite*>& satellites);
   void move(double time) override;

   void draw(ogstream& gout) override;
   void destroy(std::vector<Satellite*>& satellites) override { }

private:
   bool isThrusting;
   bool firing;
};

