/***********************************************************************
 * Header File:
 *    FRAGMENT
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    Fragment for when a satellite or part gets broken
 *    up (in other words, a part of a part).
 ************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

class TestFragment;

class Fragment : public Part
{
public:
   friend TestFragment;

   Fragment() : Part(), age(0) { }
   Fragment(const Position& pos, const Velocity& vel) : Part(pos, vel), age(0) { }
   void destroy(std::vector<Satellite*>& satellites) override { }
   void draw(ogstream& gout);

private:
   int age;
};
