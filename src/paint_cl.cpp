// leins, 23.05.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "paint_cl.h"

using namespace std;

void paint_cl::draw(float x, float y)
{
  if (mode == my_brush || mode == my_rubber)
  {
    if (mode == my_brush)
    {
      brush.draw(x, y);
    }
    else
    {
      rubber.draw(x, y);
    }
  }
} // end of draw func

void paint_cl::current_info()
{
  string str;
  stringstream stream1;
  brush_cl active_brush;

  if (mode == my_brush)
  {
    active_brush = brush;
    str = "brush";
  }
  else
  {
    active_brush = rubber;
    str = "rubber";
  }

  glBegin(GL_QUADS);
  glColor4f(1, 1, 1, 1);
  glVertex2d(0.69, -0.86);
  glVertex2d(1, -0.86);
  glVertex2d(1, -1);
  glVertex2d(0.69, -1);
  glEnd();

  // current mode
  glColor3f(0, 0, 0);
  glRasterPos2f(0.7, -0.9);
  for (unsigned int i = 0; i < str.size(); i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);

  // print current radius
  str = "radius: ";
  stream1 << active_brush.get_radius();
  str += stream1.str();

  glColor3f(0, 0, 0);
  glRasterPos2f(0.7, -0.94);
  for (unsigned int i = 0; i < str.size(); i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);

} // end of current info function

void paint_cl::set_mode(paint_mode_t newMode)
{
  mode = newMode;
} // eof

void paint_cl::init()
{
  mode = my_clear;
  color_cl c;

  c.color_init(0, 0, 0, 1);
  brush.init(RAD, c);
  c.color_init(1, 1, 1, 1);
  rubber.init(RAD, c);
  pallete.init(0.5, 0.95);
} // eof

void paint_cl::change_r(float r)
{
  brush.change_rad(r);
  rubber.change_rad(r);
}

color_cl paint_cl::get_color(float x, float y)
{
  return pallete.process(x, y);
} // eof

void paint_cl::process()
{
  static float r = RAD;

  switch (mode)
  {
  case my_exit:
    exit(0);
    break;
  case my_brush:
  case my_rubber:
      current_info();
    break;
  case my_change_r:
    r += RAD;
    if (r > 0.06)
      r = RAD;
    change_r(r);
    set_mode(my_passive);
      current_info();
    break;
  case my_pallete:
    pallete.draw();
    break;
  case my_passive:
  case my_clear:
    break;
  }
} // eof

