/***********************************************************************
 * Header File:
 *    GPSRight
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS right part.
 ************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestGPSRight;

class GPSRight : public Part
{
public:
   friend TestGPSRight;

   GPSRight() : Part() { }
   GPSRight(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 8; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};

