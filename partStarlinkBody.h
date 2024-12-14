/******************************************************************************
 * Header File:
 *    Starlink Body
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Part class for the starlink body
 *****************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestStarlinkBody;

class StarlinkBody : public Part
{
public:
   friend TestStarlinkBody;

    StarlinkBody() : Part() {}
    StarlinkBody(const Position& pos, const Velocity& vel) : Part(pos, vel) { this->radius = 2; }

   void destroy(std::vector<Satellite*>& satellites);
   void draw(ogstream& gout);
};
