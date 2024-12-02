/***********************************************************************
 * Header File:
 *    GPS
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS satellite which inherits from the base Satellite
 ************************************************************************/

#pragma once
#include "satellite.h"
#include <cassert>
#include <vector>

class Position;
class Velocity;
class ogstream;

class TestGPS;

/***************************************************
 * GPS
 * The GPS type derived from Satellite
 ***************************************************/
class GPS : public Satellite
{
public:
   friend TestGPS;

   GPS() : Satellite() { radius = 12.0; }
   GPS(const Position& pos, const Velocity& vel) : Satellite(pos, vel) { radius = 12.0; }
   ~GPS() { }

   void draw(ogstream& gout) override;
   void destroy(std::vector<Satellite*>& satellites) override;
};

