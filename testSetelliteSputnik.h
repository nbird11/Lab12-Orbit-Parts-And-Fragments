/***********************************************************************
 * Header File:
 *    TEST Sputnik
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for Sputnik
 ************************************************************************/
#pragma once

#include "fragment.h"
#include "position.h"
#include "satellite.h"
#include "satelliteSputnik.h"
#include "unitTest.h"
#include "velocity.h"
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

class TestSputnik : public UnitTest
{
public:
   void run()
   {
      destroy();

      report("Sputnik");
   }
private:
/******************************************************************************
   name: Sputnik::destroy()
   input:
   output:
 *****************************************************************************/
   void destroy()
   {  // SETUP
      vector<Satellite*> sats;
      Sputnik sputnik;

      Position parentPos = sputnik.pos;
      Velocity parentVelocity = sputnik.velocity;

      // EXERCISE
      sputnik.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 4);
      assertUnit(typeid(*(sats[0])) == typeid(Fragment));
      assertEqualsTolerance(sats[0]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[0]->direction.radians), .1);
      assertEqualsTolerance(sats[0]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[0]->direction.radians), .1);
      assertUnit(abs(sats[0]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[0]->direction.radians)));
      assertUnit(typeid(*(sats[1])) == typeid(Fragment));
      assertEqualsTolerance(sats[1]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[1]->direction.radians), .1);
      assertEqualsTolerance(sats[1]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[1]->direction.radians), .1);
      assertUnit(abs(sats[1]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[1]->direction.radians)));
      assertUnit(typeid(*(sats[2])) == typeid(Fragment));
      assertEqualsTolerance(sats[2]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[2]->direction.radians), .1);
      assertEqualsTolerance(sats[2]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[2]->direction.radians), .1);
      assertUnit(abs(sats[2]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[2]->direction.radians)));
      assertUnit(abs(sats[2]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[2]->direction.radians)));
      assertUnit(abs(sats[2]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[2]->direction.radians)));
      assertUnit(abs(sats[2]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[2]->direction.radians)));
      assertUnit(typeid(*(sats[3])) == typeid(Fragment));
      assertEqualsTolerance(sats[3]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[3]->direction.radians), .1);
      assertEqualsTolerance(sats[3]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[3]->direction.radians), .1);
      assertUnit(abs(sats[3]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[3]->direction.radians)));
      assertUnit(abs(sats[3]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[3]->direction.radians)));
      assertUnit(abs(sats[3]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[3]->direction.radians)));
      assertUnit(abs(sats[3]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[3]->direction.radians)));


      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};