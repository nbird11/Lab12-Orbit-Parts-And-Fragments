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
#include "satellite.h"
#include "satelliteSputnik.h"
#include "unitTest.h"
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
   void destroy()
   {  // SETUP
      vector<Satellite*> sats;
      Sputnik sputnik;

      // EXERCISE
      sputnik.destroy(sats);

      // VERIFY
      assertUnit(sats.size() == 4);
      assertUnit(typeid(*(sats[0])) == typeid(Fragment));
      assertUnit(typeid(*(sats[1])) == typeid(Fragment));
      assertUnit(typeid(*(sats[2])) == typeid(Fragment));
      assertUnit(typeid(*(sats[3])) == typeid(Fragment));

      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};