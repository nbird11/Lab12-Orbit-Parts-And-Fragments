/******************************************************************************
 * Header File:
 *    GPSLeft
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS left part.
 *****************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestGPSLeft;

class GPSLeft : public Part
{
public:
   friend TestGPSLeft;

   GPSLeft() : Part() { }
   GPSLeft(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 8; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};

