/***********************************************************************
 * Header File:
 *    TEST Bullet
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for Bullet
 ************************************************************************/
#pragma once

#include "projectile.h"
#include "satellite.h"
#include "unitTest.h"
using namespace std;

class TestProjectile : public UnitTest
{
public:
   void run()
   {
      default_constructor();
      move_age_decrement();
      move_age_0();

      report("Projectile");
   }
private:
   /******************************************************************************
    * name:    Default Constructor
    * input:   nothing
    * output:  pos=(0, 0))
    *****************************************************************************/
   void default_constructor()
   {  // SETUP

      // EXERCISE
      Projectile proj;

      //VERIFY
      assertEquals(proj.age, 70);
      assertEquals(proj.radius, 1.0);
      assertEquals(proj.pos.x, 0.0);
      assertEquals(proj.pos.y, 0.0);
      assertEquals(proj.velocity.dx, 0.0);
      assertEquals(proj.velocity.dy, 0.0);
      assertEquals(proj.direction.radians, 0.0);
      assertEquals(proj.angularVelocity, 0.0);
      assertEquals(proj.dead, false);

      // TEARDOWN
   }

   /******************************************************************************
    * name:    Projectile Move Age gets Decremented
    * input:   age = 5
    * output:  age = 4
    *****************************************************************************/
   void move_age_decrement()
   {  // SETUP
      Projectile proj;
      proj.age = 5;
      double time = 1;

      // EXERCISE
      proj.move(time);

      //VERIFY
      assertEquals(proj.age, 4);
      assertEquals(proj.dead, false);

      // TEARDOWN
   }
   /******************************************************************************
    * name:    Projectile Move while age 0 will kill
    * input:   age = 0
    * output:  isDead = true
    *****************************************************************************/
   void move_age_0()
   {  // SETUP
      Projectile proj;
      proj.age = 1;
      double time = 1;

      // EXERCISE
      proj.move(time);

      //VERIFY
      assertEquals(proj.age, 0);
      assertEquals(proj.dead, true);

      // TEARDOWN
   }
};