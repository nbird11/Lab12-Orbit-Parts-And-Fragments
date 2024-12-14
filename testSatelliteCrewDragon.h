/***********************************************************************
 * Header File:
 *    TEST Crew Dragon
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for the Crew Dragon
 ************************************************************************/
#pragma once

#include "fragment.h"
#include "position.h"
#include "velocity.h"
#include "partCrewDragonCenter.h"
#include "partCrewDragonLeft.h"
#include "partCrewDragonRight.h"
#include "satellite.h"
#include "satelliteDragon.h"
#include "unitTest.h"
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

      // EXERCISE
      dragon.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 5);
      assertUnit(typeid(*(sats[0])) == typeid(CrewDragonCenter));
      assertUnit(typeid(*(sats[1])) == typeid(CrewDragonLeft));
      assertUnit(typeid(*(sats[2])) == typeid(CrewDragonRight));
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

class TestCrewDragonCenter : public UnitTest
{
public: void run()
{
   CrewDragonCenter_destroy();

   report("CrewDragonCenter");
}
private:
   void CrewDragonCenter_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      CrewDragonCenter crew_dragon_center;

      Position parentPos = crew_dragon_center.pos;
      Velocity parentVelocity = crew_dragon_center.velocity;

      // EXERCISE
      crew_dragon_center.destroy(sats);

      // VERIFY
      assertEquals(sats.size(), 4);
      for (auto sat : sats)
      {
         assertUnit(typeid(*(sat)) == typeid(Fragment));
         assertUnit(sat->pos.x != parentPos.x);
         assertUnit(sat->pos.y != parentPos.y);
         assertUnit(sat->velocity.dx != parentVelocity.dx);
         assertUnit(sat->velocity.dy != parentVelocity.dy);
      }

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
   void CrewDragonLeft_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      CrewDragonLeft crew_dragon_left;

      // EXERCISE
      crew_dragon_left.destroy(sats);

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

class TestCrewDragonRight : public UnitTest
{
public: void run()
{
   CrewDragonRight_destroy();

   report("CrewDragonRight");
}
private:
   void CrewDragonRight_destroy()
   {  // SETUP
      vector<Satellite*> sats;
      CrewDragonRight crew_dragon_right;

      // EXERCISE
      crew_dragon_right.destroy(sats);

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