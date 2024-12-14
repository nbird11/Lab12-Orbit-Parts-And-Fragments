/***********************************************************************
 * Header File:
 *    TEST hubble
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for the hubble
 ************************************************************************/
#pragma once

#include "fragment.h"
#include "partHubbleComputer.h"
#include "partHubbleLeft.h"
#include "partHubbleRight.h"
#include "partHubbleTelescope.h"
#include "position.h"
#include "satellite.h"
#include "satelliteHubble.h"
#include "unitTest.h"
#include "velocity.h"
#include <cmath>
#include <cstdlib>
#include <vector>

class TestHubble : public UnitTest
{
public:
   void run()
   {
      Hubble_destroy();

      report("Hubble");
   }
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void Hubble_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      Hubble hubble;
      Position parentPos = hubble.pos;
      Velocity parentVelocity = hubble.velocity;

      // EXERCISE
      hubble.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 4);
      assertUnit(typeid(*(sats[0])) == typeid(HubbleTelescope));
      assertEqualsTolerance(sats[0]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[0]->direction.radians), .1);
      assertEqualsTolerance(sats[0]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[0]->direction.radians), .1);
      assertUnit(abs(sats[0]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[0]->direction.radians)));
      assertUnit(typeid(*(sats[1])) == typeid(HubbleLeft));
      assertEqualsTolerance(sats[1]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[1]->direction.radians), .1);
      assertEqualsTolerance(sats[1]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[1]->direction.radians), .1);
      assertUnit(abs(sats[1]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[1]->direction.radians)));
      assertUnit(typeid(*(sats[2])) == typeid(HubbleRight));
      assertEqualsTolerance(sats[2]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[2]->direction.radians), .1);
      assertEqualsTolerance(sats[2]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[2]->direction.radians), .1);
      assertUnit(abs(sats[2]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[2]->direction.radians)));
      assertUnit(abs(sats[2]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[2]->direction.radians)));
      assertUnit(abs(sats[2]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[2]->direction.radians)));
      assertUnit(abs(sats[2]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[2]->direction.radians)));
      assertUnit(typeid(*(sats[3])) == typeid(HubbleComputer));
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

class TestHubbleTelescope : public UnitTest
{
public: void run()
{
   HubbleTelescope_destroy();

   report("HubbleTelescope");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void HubbleTelescope_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      HubbleTelescope hubble_telescope;
      Position parentPos = hubble_telescope.pos;
      Velocity parentVelocity = hubble_telescope.velocity;

      // EXERCISE
      hubble_telescope.destroy(sats);

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

class TestHubbleRight : public UnitTest
{
public: void run()
{
   HubbleRight_destroy();

   report("HubbleRight");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void HubbleRight_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      HubbleRight hubble_right;
      Position parentPos = hubble_right.pos;
      Velocity parentVelocity = hubble_right.velocity;

      // EXERCISE
      hubble_right.destroy(sats);

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

class TestHubbleLeft : public UnitTest
{
public: void run()
{
   HubbleLeft_destroy();

   report("HubbleLeft");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void HubbleLeft_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      HubbleLeft hubble_left;
      Position parentPos = hubble_left.pos;
      Velocity parentVelocity = hubble_left.velocity;

      // EXERCISE
      hubble_left.destroy(sats);

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

class TestHubbleComputer : public UnitTest
{
public: void run()
{
   HubbleComputer_destroy();

   report("HubbleComputer");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void HubbleComputer_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      HubbleComputer hubble_computer;
      Position parentPos = hubble_computer.pos;
      Velocity parentVelocity = hubble_computer.velocity;

      // EXERCISE
      hubble_computer.destroy(sats);

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