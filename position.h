/******************************************************************************
 * Header File:
 *    Point : The representation of a position 
 * Author:
 *    Nathan Bird, Brock Hoskins, Jared Davey
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 *****************************************************************************/

#pragma once

#include <cmath>
#include <iosfwd>

class TestPosition;
class Acceleration;
class Velocity;

class TestSatellite;
class TestShip;
class TestHubble;
class TestGPS;
class TestStarlink;
class TestCrewDragon;
class TestCrewDragonCenter;
class TestCrewDragonLeft;
class TestCrewDragonRight;
class TestGPSCenter;
class TestGPSLeft;
class TestGPSRight;
class TestHubbleComputer;
class TestHubbleLeft;
class TestHubbleRight;
class TestHubbleTelescope;
class TestSputnik;
class TestStarlinkBody;
class TestStarlinkArray;
class TestProjectile;

/******************************************************************************
 * Position
 * A single position on the field in Meters  
 *****************************************************************************/
class Position
{
public:
   friend TestPosition;
   friend TestSatellite;
   friend TestShip;
   friend TestHubble;
   friend TestGPS;
   friend TestStarlink;
   friend TestCrewDragon;
   friend TestCrewDragonCenter;
   friend TestCrewDragonLeft;
   friend TestCrewDragonRight;
   friend TestGPSCenter;
   friend TestGPSLeft;
   friend TestGPSRight;
   friend TestHubbleComputer;
   friend TestHubbleLeft;
   friend TestHubbleRight;
   friend TestHubbleTelescope;
   friend TestSputnik;
   friend TestStarlinkBody;
   friend TestStarlinkArray;
   friend TestProjectile;

   // constructors
   Position()            : x(0.0), y(0.0)  {}
   Position(double x, double y);
   Position(const Position & pt) : x(pt.x), y(pt.y) {}
   Position& operator = (const Position& pt);

   // getters
   double getMetersX()       const { return x;                    }
   double getMetersY()       const { return y;                    }
   double getPixelsX()       const { return x / metersFromPixels; }
   double getPixelsY()       const { return y / metersFromPixels; }

   // setters
   void setMeters(double xMeters, double yMeters) {x = xMeters; y = yMeters; }
   void setMetersX(double xMeters)     { x = xMeters;           }
   void setMetersY(double yMeters)     { y = yMeters;           }
   void setPixelsX(double xPixels)     { x = xPixels * metersFromPixels;      }
   void setPixelsY(double yPixels)     { y = yPixels * metersFromPixels;      }
   void addMetersX(double dxMeters)    { setMetersX(getMetersX() + dxMeters); }
   void addMetersY(double dyMeters)    { setMetersY(getMetersY() + dyMeters); }
   void addPixelsX(double dxPixels)    { setPixelsX(getPixelsX() + dxPixels); }
   void addPixelsY(double dyPixels)    { setPixelsY(getPixelsY() + dyPixels); }
   void addPixels(double pixels, double directionRadians);

   void add(const Velocity& v, const Acceleration&, double time);

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   double getZoom() const { return metersFromPixels; }

private:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
};

/******************************************************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *****************************************************************************/
inline double computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (
      pos1.getMetersX() - pos2.getMetersX()) + (pos1.getMetersY() - 
      pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
}

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);


/******************************************************************************
 * PT
 * Trivial point
 *****************************************************************************/
struct PT
{
   double x;
   double y;
};


