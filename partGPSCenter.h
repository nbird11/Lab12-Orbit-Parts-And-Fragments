/******************************************************************************
 * Header File:
 *    GPSCenter
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS center part.
 *****************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestGPSCenter;

class GPSCenter : public Part
{
public:
   friend TestGPSCenter;

   GPSCenter() : Part() { }
   GPSCenter(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 7; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};

