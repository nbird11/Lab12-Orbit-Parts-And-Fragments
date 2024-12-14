/******************************************************************************
 * Header File:
 *    Starlink Body
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The starlink array
 *****************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestStarlinkArray;

class StarlinkArray : public Part
{
public:
   friend TestStarlinkArray;

    StarlinkArray() : Part() {}
    StarlinkArray(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 4; }

   void destroy(std::vector<Satellite*>& satellites);
   void draw(ogstream& gout);
};

