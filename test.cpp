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
#include "testSatelliteGPS.h"
#include "testSatelliteShip.h"
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
   TestGPS().run();
   TestShip().run();
}
