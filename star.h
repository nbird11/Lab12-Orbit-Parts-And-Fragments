/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once
#include "position.h"
#include "uiDraw.h"
#include <vector>

using namespace std;

 /*****************************************************
  * STAR
  * A star that twinkles
  *****************************************************/
class Stars
{
public:
   Stars() : phase(100) { }

  /************************************************************
  * RESET
  * Give the given star a random coordinate and a random phase
  *************************************************************/
   void reset(double width, double height)
   {
      double newX = random(-(width / 2.0), width / 2.0);
      double newY = random(-(height / 2.0), height / 2.0);
      unsigned char newPhase = random(0, 300);

      pos.setPixelsX(newX);
      pos.setPixelsY(newY);
      phase = newPhase;
   }

   /************************************************************
   * DRAW
   * Iterate through list of stars and display each one.
   *************************************************************/
   void draw(ogstream& gout) const
   {
      for (auto item : getStars())
      {
         gout.drawStar(item->pos, item->phase++);
      }
   }

   const vector<Stars*>& getStars() const
   {
      return stars;
   }

   /************************************************************
   * INITIALIZE STARS
   * Fill the vector with 50 stars and 
   * assign each one a random coordinate and phase.
   *************************************************************/
   void initializeStars(int count, Position ptUpperRight)
   {
      stars.clear();
      stars.reserve(count);
      for (int i = 0; i < count; ++i)
      {
         auto star = new Stars;
         star->reset(ptUpperRight.getPixelsX(), ptUpperRight.getPixelsY());
         stars.push_back(star);
      }
   }

private:
   Position pos;
   unsigned char phase;
   vector<Stars*> stars;
};