/******************************************************************************
 * Header File:
 *    Hubble Telescope
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Hubble Telescope.
 *****************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestHubbleTelescope;

class HubbleTelescope :
    public Part
{
public:
   friend TestHubbleTelescope;

   HubbleTelescope() : Part() {}
   HubbleTelescope(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 10; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};
