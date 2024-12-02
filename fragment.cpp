/***********************************************************************
 * Source File:
 *    FRAGMENT
 * Author:
 *    Nathan Bird, Brock Hoskins, Jared Davey
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "fragment.h"
#include "uiDraw.h"

void Fragment::draw(ogstream& gout)
{
   gout.drawFragment(pos, direction.getRadians());
}
