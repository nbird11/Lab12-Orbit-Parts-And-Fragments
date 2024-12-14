/******************************************************************************
 * Header File:
 *    FRAGMENT
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    Fragment for when a satellite or part gets broken
 *    up (in other words, a part of a part).
 *****************************************************************************/

#pragma once
#include "part.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

// hoursPerDay * minutesPerHour * frameRate
#define timePerFrame 24.0 * 60.0 / 30.0

class Position;
class Velocity;

class TestFragment;

class Fragment : public Part
{
public:
   friend TestFragment;

   Fragment() : Part(), age(random(50, 100))
   {
      this->angularVelocity = random(0.0, 0.75);
   }
   Fragment(const Position& pos, const Velocity& vel) : Part(pos, vel), 
      age(random(50, 100))
   {
      this->angularVelocity = random(0.0, 0.75);
   }
   void move(double time) override {
      Part::move(time);
      age--;
      if (age == 0) kill();
   }
   void destroy(std::vector<Satellite*>& satellites) override { }
   void draw(ogstream& gout);

private:
   int age;
};
