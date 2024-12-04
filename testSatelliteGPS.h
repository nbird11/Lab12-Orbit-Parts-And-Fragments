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
#include "satellite.h"
#include "satelliteGPS.h"
#include "unitTest.h"
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
   void GPS_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      GPS gps;

      // EXERCISE
      gps.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 5);
      assertUnit(typeid(*(sats[0])) == typeid(GPSCenter));
      assertUnit(typeid(*(sats[1])) == typeid(GPSLeft));
      assertUnit(typeid(*(sats[2])) == typeid(GPSRight));
      assertUnit(typeid(*(sats[3])) == typeid(Fragment));
      assertUnit(typeid(*(sats[4])) == typeid(Fragment));

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
   void GPSCenter_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      GPSCenter gps_center;

      // EXERCISE
      gps_center.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 3);
      for (auto sat : sats) // Check to see if they're all Fragments
         assertUnit(typeid(*(sat)) == typeid(Fragment));

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
   void GPSLeft_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      GPSLeft gps_left;

      // EXERCISE
      gps_left.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 3);
      for (auto sat : sats) // Check to see if they're all Fragments
         assertUnit(typeid(*(sat)) == typeid(Fragment));

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
   void GPSRight_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      GPSRight gps_right;

      // EXERCISE
      gps_right.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 3);
      for (auto sat : sats) // Check to see if they're all Fragments
         assertUnit(typeid(*(sat)) == typeid(Fragment));

      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};