/******************************************************************************
 * Header File:
 *    Hubble Left
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The left part of the Hubble satellite.
 *****************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestHubbleLeft;

class HubbleLeft :
    public Part
{
public:
   friend TestHubbleLeft;

   HubbleLeft() : Part() {}
   HubbleLeft(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 8; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};
