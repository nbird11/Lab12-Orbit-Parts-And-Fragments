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
   void destroy()
   {  // SETUP
      vector<Satellite*> sats;
      Starlink starlink;

      // EXERCISE
      starlink.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 4);
      assertUnit(typeid(*(sats[0])) == typeid(StarlinkBody));
      assertUnit(typeid(*(sats[1])) == typeid(StarlinkArray));
      assertUnit(typeid(*(sats[2])) == typeid(Fragment));
      assertUnit(typeid(*(sats[3])) == typeid(Fragment));

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
   void StarlinkBody_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      StarlinkBody starlink_body;

      // EXERCISE
      starlink_body.destroy(sats);

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

class TestStarlinkArray : public UnitTest
{
public:
   void run()
   {
      StarlinkArray_destroy();

      report("StarlinkArray");
   }
private:
   void StarlinkArray_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      StarlinkArray starlink_array;

      // EXERCISE
      starlink_array.destroy(sats);

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