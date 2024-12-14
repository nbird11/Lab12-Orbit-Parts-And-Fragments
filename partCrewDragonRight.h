/******************************************************************************
 * Header File:
 *    Crew Dragon Right
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The right part of the Crew Dragon Satellite.
 *****************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestCrewDragonRight;

class CrewDragonRight :
    public Part
{
public:
   friend TestCrewDragonRight;

   CrewDragonRight() : Part() {}
   CrewDragonRight(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 6; }

   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
};

