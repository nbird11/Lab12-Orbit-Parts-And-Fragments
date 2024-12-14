/******************************************************************************
 * Header File:
 *    TEST Crew Dragon
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for the Crew Dragon
 *****************************************************************************/
#pragma once

#include "angle.h"
#include "fragment.h"
#include "partCrewDragonCenter.h"
#include "partCrewDragonLeft.h"
#include "partCrewDragonRight.h"
#include "position.h"
#include "satellite.h"
#include "satelliteDragon.h"
#include "unitTest.h"
#include "velocity.h"
#include <cmath>
#include <vector>
using namespace std;

class TestCrewDragon : public UnitTest
{
public:
   void run()
   {
      destroy();

      report("Crew Dragon");
   }
private:
   void destroy()
   {  // SETUP
      vector<Satellite*> sats;
      CrewDragon dragon;
      Position parentPos = dragon.pos;
      Velocity parentVelocity = dragon.velocity;

      // EXERCISE
      dragon.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 5);
      assertUnit(typeid(*(sats[0])) == typeid(CrewDragonCenter));
      assertEqualsTolerance(sats[0]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[0]->direction.radians), .1);
      assertEqualsTolerance(sats[0]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[0]->direction.radians), .1);
      assertUnit(abs(sats[0]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[0]->direction.radians)));
      assertUnit(typeid(*(sats[1])) == typeid(CrewDragonLeft));
      assertEqualsTolerance(sats[1]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[1]->direction.radians), .1);
      assertEqualsTolerance(sats[1]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[1]->direction.radians), .1);
      assertUnit(abs(sats[1]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[1]->direction.radians)));
      assertUnit(typeid(*(sats[2])) == typeid(CrewDragonRight));
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
      assertUnit(typeid(*(sats[4])) == typeid(Fragment));
      assertEqualsTolerance(sats[4]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[4]->direction.radians), .1);
      assertEqualsTolerance(sats[4]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[4]->direction.radians), .1);
      assertUnit(abs(sats[4]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[4]->direction.radians)));
      assertUnit(abs(sats[4]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[4]->direction.radians)));
      assertUnit(abs(sats[4]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[4]->direction.radians)));
      assertUnit(abs(sats[4]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[4]->direction.radians)));

      // TEARDOWN
      for (Satellite* sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};

class TestCrewDragonCenter : public UnitTest
{
public: void run()
{
   CrewDragonCenter_destroy();

   report("CrewDragonCenter");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void CrewDragonCenter_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      CrewDragonCenter crew_dragon_center;
      Angle parentDir = crew_dragon_center.direction;
      Position parentPos = crew_dragon_center.pos;
      Velocity parentVelocity = crew_dragon_center.velocity;

      // EXERCISE
      crew_dragon_center.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 4);
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

class TestCrewDragonLeft : public UnitTest
{
public: void run()
{
   CrewDragonLeft_destroy();

   report("CrewDragonLeft");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void CrewDragonLeft_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      CrewDragonLeft crew_dragon_left;

      Position parentPos = crew_dragon_left.pos;
      Velocity parentVelocity = crew_dragon_left.velocity;

      // EXERCISE
      crew_dragon_left.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 2);
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

      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};

class TestCrewDragonRight : public UnitTest
{
public: void run()
{
   CrewDragonRight_destroy();

   report("CrewDragonRight");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/

   void CrewDragonRight_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      CrewDragonRight crew_dragon_right;

      Position parentPos = crew_dragon_right.pos;
      Velocity parentVelocity = crew_dragon_right.velocity;

      // EXERCISE
      crew_dragon_right.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 2);
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

      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};