/***********************************************************************
 * Header File:
 *    Crew Dragon Left
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The left part of the Crew Dragon Satellite.
 ************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestCrewDragonLeft;

class CrewDragonLeft :
    public Part
{
public:
   friend TestCrewDragonLeft;

   CrewDragonLeft() : Part() {}
   CrewDragonLeft(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 6; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};