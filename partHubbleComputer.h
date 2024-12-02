/***********************************************************************
 * Header File:
 *    HubbleComputer
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Hubble Computer.
 ************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestHubbleComputer;

class HubbleComputer : public Part
{
public:
   friend TestHubbleComputer;

   HubbleComputer(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 7; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};
