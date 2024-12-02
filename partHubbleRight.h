/***********************************************************************
 * Header File:
 *    Hubble Right
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The right part of the Hubble satellite.
 ************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestHubbleRight;

class HubbleRight :
    public Part
{
public:
   friend TestHubbleRight;

   HubbleRight(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 8; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};
