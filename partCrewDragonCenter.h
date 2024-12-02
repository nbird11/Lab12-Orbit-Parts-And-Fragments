/***********************************************************************
 * Header File:
 *    Crew Dragon Center
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The center part of the Crew Dragon Satellite.
 ************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestCrewDragonCenter;

class CrewDragonCenter :
    public Part
{
public:
   friend TestCrewDragonCenter;

   CrewDragonCenter(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 6; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};

