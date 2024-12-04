/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testAcceleration.h"
#include "testAngle.h"
#include "testPosition.h"
#include "testSatellite.h"
#include "testSatelliteCrewDragon.h"
#include "testSatelliteGPS.h"
#include "testSatelliteHubble.h"
#include "testSatelliteShip.h"
#include "testSatelliteStarlink.h"
#include "testSetelliteSputnik.h"
#include "testVelocity.h"

#ifdef _WIN32
  #include <windows.h>
  #include <iostream>
  using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   TestPosition().run();
   TestVelocity().run();
   TestAcceleration().run();
   TestAngle().run();

   TestSatellite().run();

   TestSputnik().run();

   TestGPS().run();
   TestGPSCenter().run();
   TestGPSLeft().run();
   TestGPSRight().run();

   TestHubble().run();
   TestHubbleTelescope().run();
   TestHubbleLeft().run();
   TestHubbleRight().run();
   TestHubbleComputer().run();

   TestCrewDragon().run();
   TestCrewDragonCenter().run();
   TestCrewDragonLeft().run();
   TestCrewDragonRight().run();

   TestStarlink().run();
   TestStarlinkArray().run();
   TestStarlinkBody().run();

   TestShip().run();
}
