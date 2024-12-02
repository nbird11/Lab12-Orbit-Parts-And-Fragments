/***********************************************************************
 * Header File:
 *    Part
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The base Part class for each type satellite for when it gets broken
 *    up.
 ************************************************************************/

#pragma once
#include "satellite.h"
#include <vector>

class Position;
class Velocity;

class TestPart;

class Part : public Satellite
{
public:
   friend TestPart;

   Part(const Position& pos, const Velocity& vel);
   
   virtual void destroy(std::vector<Satellite*>& satellites) override = 0;
};

