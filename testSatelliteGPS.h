/***********************************************************************
 * Header File:
 *    TEST GPS
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for the GPS
 ************************************************************************/
#pragma once

#include "fragment.h"
#include "partGPSCenter.h"
#include "partGPSLeft.h"
#include "partGPSRight.h"
#include "position.h"
#include "satellite.h"
#include "satelliteGPS.h"
#include "unitTest.h"
#include "velocity.h"
#include <cmath>
#include <cstdlib>
#include <typeinfo>
#include <vector>
using namespace std;

class TestGPS : public UnitTest
{
public:
   void run()
   {
      GPS_destroy();

      report("GPS");
   }
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void GPS_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      GPS gps;
      Position parentPos = gps.pos;
      Velocity parentVelocity = gps.velocity;

      // EXERCISE
      gps.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 5);
      assertUnit(typeid(*(sats[0])) == typeid(GPSCenter));
      assertEqualsTolerance(sats[0]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[0]->direction.radians), .1);
      assertEqualsTolerance(sats[0]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[0]->direction.radians), .1);
      assertUnit(abs(sats[0]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[0]->direction.radians)));
      assertUnit(abs(sats[0]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[0]->direction.radians)));
      assertUnit(typeid(*(sats[1])) == typeid(GPSLeft));
      assertEqualsTolerance(sats[1]->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sats[1]->direction.radians), .1);
      assertEqualsTolerance(sats[1]->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sats[1]->direction.radians), .1);
      assertUnit(abs(sats[1]->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sats[1]->direction.radians)));
      assertUnit(abs(sats[1]->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sats[1]->direction.radians)));
      assertUnit(typeid(*(sats[2])) == typeid(GPSRight));
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

class TestGPSCenter : public UnitTest
{
public: void run()
{
   GPSCenter_destroy();

   report("GPSCenter");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void GPSCenter_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      GPSCenter gps_center;

      Position parentPos = gps_center.pos;
      Velocity parentVelocity = gps_center.velocity;

      // EXERCISE
      gps_center.destroy(sats);

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

class TestGPSLeft : public UnitTest
{
public: void run()
{
   GPSLeft_destroy();

   report("GPSLeft");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void GPSLeft_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      GPSLeft gps_left;

      Position parentPos = gps_left.pos;
      Velocity parentVelocity = gps_left.velocity;

      // EXERCISE
      gps_left.destroy(sats);

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

class TestGPSRight : public UnitTest
{
public: void run()
{
   GPSRight_destroy();

   report("GPSRight");
}
private:
/******************************************************************************
   name:
   input:
   output:
 *****************************************************************************/
   void GPSRight_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      GPSRight gps_right;
      Position parentPos = gps_right.pos;
      Velocity parentVelocity = gps_right.velocity;

      // EXERCISE
      gps_right.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 3);
      for (auto sat : sats) // Check to see if they're all Fragments
      {
         assertUnit(typeid(*(sat)) == typeid(Fragment));
         assertEqualsTolerance(sat->pos.x, parentPos.x + (20.0 * Position::metersFromPixels) * sin(sat->direction.radians), .1);
         assertEqualsTolerance(sat->pos.y, parentPos.y + (20.0 * Position::metersFromPixels) * cos(sat->direction.radians), .1);
         assertUnit(abs(sat->velocity.dx) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * sin(sat->direction.radians)));
         assertUnit(abs(sat->velocity.dx) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * sin(sat->direction.radians)));
         assertUnit(abs(sat->velocity.dy) >= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 5000.0) * cos(sat->direction.radians)));
         assertUnit(abs(sat->velocity.dy) <= abs((atan2(parentVelocity.dx, parentVelocity.dy) + 9000.0) * cos(sat->direction.radians)));
      }


      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};