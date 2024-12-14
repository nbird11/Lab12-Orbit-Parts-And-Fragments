/***********************************************************************
 * Header File:
 *    TEST Starlink
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for Starlink
 ************************************************************************/
#pragma once

#include "fragment.h"
#include "partStarlinkArray.h"
#include "partStarlinkBody.h"
#include "satellite.h"
#include "satelliteStarlink.h"
#include "unitTest.h"
#include <vector>
using namespace std;

class TestStarlink : public UnitTest
{
public:
   void run()
   {
      destroy();

      report("Starlink");
   }
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void destroy()
   {  // SETUP
      vector<Satellite*> sats;
      Starlink starlink;
      Position parentPos = starlink.pos;
      Velocity parentVelocity = starlink.velocity;

      // EXERCISE
      starlink.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 4);
      assertUnit(typeid(*(sats[0])) == typeid(StarlinkBody));
      assertEqualsTolerance(sats[0]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[0]->direction.radians), .1);
      assertEqualsTolerance(sats[0]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[0]->direction.radians), .1);
      assertUnit(abs(sats[0]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[0]->direction.radians)));
      assertUnit(typeid(*(sats[1])) == typeid(StarlinkArray));
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
      for (Satellite* sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};

class TestStarlinkBody : public UnitTest
{
public:
   void run()
   {
      StarlinkBody_destroy();

      report("StarlinkBody");
   }
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void StarlinkBody_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      StarlinkBody starlink_body;

      Position parentPos = starlink_body.pos;
      Velocity parentVelocity = starlink_body.velocity;

      // EXERCISE
      starlink_body.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 3);
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

      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};

class TestStarlinkArray : public UnitTest
{
public:
   void run()
   {
      StarlinkArray_destroy();

      report("StarlinkArray");
   }
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void StarlinkArray_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      StarlinkArray starlink_array;

      Position parentPos = starlink_array.pos;
      Velocity parentVelocity = starlink_array.velocity;

      // EXERCISE
      starlink_array.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 3);
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

      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};