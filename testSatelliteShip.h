/******************************************************************************
 * Header File:
 *    TEST SHIP
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for the ship
 *****************************************************************************/
#pragma once

#include "satellite.h"
#include "satelliteShip.h"
#include "projectile.h"
#include "unitTest.h"
#include <vector>

class TestShip : public UnitTest
{
public:
   void run()
   {
      move_thrust();
      move_no_thrust();
      fire_stationary();
      fire_moving_up_pointed_up();
      fire_moving_right_pointed_up();

      report("Ship");
   }
private:
/******************************************************************************
    * MOVE : THRUST
    *  Move the ship while thrusting
 *****************************************************************************/
   void move_thrust()
   {  // setup
      Ship s;
      s.isThrusting = true;
      s.pos.x = 500000000;
      s.pos.y = 500000000;
      s.velocity.dx = 0;
      s.velocity.dy = 0;
      s.direction.radians = 0;
      double dt = 48;

      // exercise
      s.move(dt);

      // verify
      // s_t = s_0 + v(t) + a(t * t)
      assertUnit(s.isThrusting == true);
      assertEqualsTolerance(s.pos.x, 499999998.7, .001);
      assertEqualsTolerance(s.pos.y, 500004606.7, .001);
      assertEqualsTolerance(s.velocity.dx, 0.0, .1);
      assertEqualsTolerance(s.velocity.dy, 96.0, .1);
      assertUnit(dt == 48);
      assertUnit(s.direction.radians == 0);
   }  // teardown

   void move_no_thrust()
   {  // setup
      Ship s;
      s.isThrusting = false;
      s.pos.x = 500000000;
      s.pos.y = 500000000;
      s.velocity.dx = 0;
      s.velocity.dy = 0;
      s.direction.radians = 0;
      double dt = 48;

      // exercise
      s.move(dt);

      // verify
      assertUnit(s.isThrusting == false);
      assertEqualsTolerance(s.pos.x, 499999998.7, .001);
      assertEqualsTolerance(s.pos.y, 499999998.7, .001);
      assertEqualsTolerance(s.velocity.dx, 0.0, .1);
      assertEqualsTolerance(s.velocity.dy, 0.0, .1);
      assertUnit(dt == 48);
      assertUnit(s.direction.radians == 0);

   }

   void fire_stationary()
   {  // setup
      Ship s;
      s.isThrusting = false;
      s.pos.x = 500000000;
      s.pos.y = 500000000;
      s.velocity.dx = 0;
      s.velocity.dy = 0;
      s.direction.radians = 0;
      vector<Satellite*> sats;


      // exercise
      s.fire(sats);

      // verify
      assertEquals(sats.size(), 1);
      assertUnit(typeid(*(sats[0])) == typeid(Projectile));
      assertEquals(sats[0]->pos.x, 500000000);
      assertEquals(sats[0]->pos.y, 500000000 + (
         19 * Position::metersFromPixels));
      assertEquals(sats[0]->velocity.dx, 0.0);
      assertEquals(sats[0]->velocity.dy, 9000.0);

      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }

   void fire_moving_up_pointed_up()
   {  // setup
      Ship s;
      s.isThrusting = false;
      s.pos.x = 500000000;
      s.pos.y = 500000000;
      s.velocity.dx = 0;
      s.velocity.dy = 22;
      s.direction.radians = 0;
      vector<Satellite*> sats;


      // exercise
      s.fire(sats);

      // verify
      assertEquals(sats.size(), 1);
      assertUnit(typeid(*(sats[0])) == typeid(Projectile));
      assertEquals(sats[0]->pos.x, 500000000);
      assertEquals(sats[0]->pos.y, 500000000 + (
         19 * Position::metersFromPixels));
      assertEquals(sats[0]->velocity.dx, 0.0);
      assertEquals(sats[0]->velocity.dy, 9022.0);

      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }

   void fire_moving_right_pointed_up()
   {  // setup
      Ship s;
      s.isThrusting = false;
      s.pos.x = 500000000;
      s.pos.y = 500000000;
      s.velocity.dx = 11;
      s.velocity.dy = 0;
      s.direction.radians = 0;
      vector<Satellite*> sats;


      // exercise
      s.fire(sats);

      // verify
      assertEquals(sats.size(), 1);
      assertUnit(typeid(*(sats[0])) == typeid(Projectile));
      assertEquals(sats[0]->pos.x, 500000000);
      assertEquals(sats[0]->pos.y, 500000000 + (
         19 * Position::metersFromPixels));
      assertEquals(sats[0]->velocity.dx, 11.0);
      assertEquals(sats[0]->velocity.dy, 9000.0);

      // TEARDOWN
      for (auto sat : sats)
      {
         delete sat;
         sat = nullptr;
      }
   }
};