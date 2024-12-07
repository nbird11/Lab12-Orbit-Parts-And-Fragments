/*************************************************************
 * 1. Name:
 *      Nathan Bird, Jared Davey, Brock Hoskins
 * 2. Assignment Name:
 *      Lab 12: Orbit Simulator
 * 3. Assignment Description:
 *      Implement the code and unit tests for all Satellites.
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include "position.h"   // for POSITION
#include "satellite.h"
#include "satelliteDragon.h"
#include "satelliteGPS.h"
#include "satelliteHubble.h"
#include "satelliteShip.h"
#include "satelliteSputnik.h"
#include "satelliteStarlink.h"
#include "star.h"
#include "test.h"
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "uiInteract.h" // for INTERFACE
#include "velocity.h"
#include <cstdlib>
#include <vector>
using namespace std;

#define PI           3.14159265358979
#define RADIUS_EARTH 6378000.0  // meters


// struct star {
//    Position pos;
//    unsigned char phase;
// };

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      timePerFrame(24.0 /*hoursPerDay*/ * 60.0 /*minutesPerHour*/ / 30.0 /*frameRate*/),
      ship(new Ship)
   {
      satellites.push_back(new Sputnik(Position(-36515095.13, 21082000.0), Velocity(2050.0, 2684.68)));

      satellites.push_back(new GPS(Position(0.0, 26560000.0), Velocity(-3880.0, 0.0)));
      satellites.push_back(new GPS(Position(0.0, -26560000.0), Velocity(3880.0, 0.0)));
      satellites.push_back(new GPS(Position(23001634.72, 13280000.0), Velocity(-1940.00, 3360.18)));
      satellites.push_back(new GPS(Position(23001634.72, -13280000.0), Velocity(1940.00, 3360.18)));
      satellites.push_back(new GPS(Position(-23001634.72, -13280000.0), Velocity(1940.00, -3360.18)));
      satellites.push_back(new GPS(Position(-23001634.72, 13280000.0), Velocity(-1940.00, -3360.18)));

      satellites.push_back(new Hubble(Position(0.0, -42164000.0), Velocity(-3100, 0.0)));

      satellites.push_back(new CrewDragon(Position(0.0, 8000000.0), Velocity(-7900.0, 0.0)));

      satellites.push_back(new Starlink(Position(0.0, -13020000.0), Velocity(5800.0, 0.0)));

      angleEarth = 0;
   }

   void handleCollisions()
   {
      for (auto it1 = satellites.begin(); next(it1) != satellites.end(); it1++)
      {
         for (auto it2 = next(it1); it2 != satellites.end(); it2++)
         {
            // Sattelite collition
            if (!(*it1)->isDead() && !(*it2)->isDead())
            {
               if (abs((*it1)->getPosition().getPixelsX() - (*it2)->getPosition().getPixelsX()) <= ((*it1)->getRadius() + (*it2)->getRadius()) &&
                   abs((*it1)->getPosition().getPixelsY() - (*it2)->getPosition().getPixelsY()) <= ((*it1)->getRadius() + (*it2)->getRadius()))
               {
                  (*it1)->kill();
                  (*it2)->kill();
               }

            }
         }
         // If the sattelite is in the area of the earth, kill it.
         if (computeDistance(Position(0.0, 0.0), (*it1)->getPosition()) <= RADIUS_EARTH)
         {
              (*it1)->kill();
         }
         if (ship != nullptr)
         {
            if (computeDistance(Position(0.0, 0.0), ship->getPosition()) <= RADIUS_EARTH)
            {
               ship->kill();
            }
         }
      }

      vector<Satellite*> newSats;
      for (auto itSat = satellites.begin(); itSat != satellites.end(); )
      {
         if ((*itSat)->isDead())
         {
            (*itSat)->destroy(newSats);
            itSat = satellites.erase(itSat);
         }
         else
         {
            ++itSat;
         }
      }
      if (ship != nullptr && ship->isDead())
      {
         delete ship;
         ship = nullptr;
      }
      if (!newSats.empty())
      {
         satellites.insert(satellites.end(), make_move_iterator(newSats.begin()), make_move_iterator(newSats.end()));
      }
   }

   vector<Satellite*> satellites;
   Ship* ship;
   Position ptStar;
   Position ptUpperRight;
   Stars stars;

   double timePerFrame;
   double angleEarth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // perform all the game logic
   //

   // rotate the earth
   double rpf = -(2 * PI / 30.0 /*frameRate*/) * (pDemo->timePerFrame * 30.0 / 86400 /*secondsPerDay*/);

   pDemo->angleEarth += rpf;

   // 
   // move
   //
   if (pDemo->ship != nullptr)
      pDemo->ship->input(pUI, pDemo->timePerFrame, pDemo->satellites);
   for (Satellite* sat : pDemo->satellites)
   {
      sat->move(pDemo->timePerFrame);
   }

   //
   // collide
   //
   pDemo->handleCollisions();

   //
   // draw everything
   //
   ogstream gout;

   for (Satellite* sat : pDemo->satellites)
      sat->draw(gout);
   if (pDemo->ship != nullptr)
      pDemo->ship->draw(gout);

   pDemo->stars.draw(gout);

   // draw the earth
   Position pt;
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
                "Demo",   /* name on the window */
                ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);
   demo.stars.initializeStars(500, ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
