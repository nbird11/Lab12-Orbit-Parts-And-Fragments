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
#include "satellite.h"
#include "satelliteHubble.h"
#include "unitTest.h"
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
   void Hubble_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      Hubble hubble;

      // EXERCISE
      hubble.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 4);
      assertUnit(typeid(*(sats[0])) == typeid(HubbleTelescope));
      assertUnit(typeid(*(sats[1])) == typeid(HubbleLeft));
      assertUnit(typeid(*(sats[2])) == typeid(HubbleRight));
      assertUnit(typeid(*(sats[3])) == typeid(HubbleComputer));

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
   void HubbleTelescope_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      HubbleTelescope hubble_telescope;

      // EXERCISE
      hubble_telescope.destroy(sats);

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

class TestHubbleRight : public UnitTest
{
public: void run()
{
   HubbleRight_destroy();

   report("HubbleRight");
}
private:
   void HubbleRight_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      HubbleRight hubble_right;

      // EXERCISE
      hubble_right.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 2);
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

class TestHubbleLeft : public UnitTest
{
public: void run()
{
   HubbleLeft_destroy();

   report("HubbleLeft");
}
private:
   void HubbleLeft_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      HubbleLeft hubble_left;

      // EXERCISE
      hubble_left.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 2);
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

class TestHubbleComputer : public UnitTest
{
public: void run()
{
   HubbleComputer_destroy();

   report("HubbleComputer");
}
private:
   void HubbleComputer_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      HubbleComputer hubble_computer;

      // EXERCISE
      hubble_computer.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 2);
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