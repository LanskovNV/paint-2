// leins 17.04.2018

#include <iostream>
#include <cstring>
#include <GL/gl.h>
#include <GL/glut.h>
#include "button_cl.h"

using namespace std;

void button_cl::change_state()
{
  state = !state;
} // end of change_state function

void button_cl::draw()
{
    color_cl drawColor;
    int length = name.size();
    float xLeft = pos.get_x();
    float yUp = pos.get_y();

    // setting up color (by state)
    if (!state)
        drawColor = color;
    else
        drawColor = hightColor;

    // draw button
    glBegin(GL_QUADS);
    glColor4f(drawColor.get_r(), drawColor.get_g(), drawColor.get_b(), drawColor.get_a());
    glVertex2d(xLeft, yUp);
    glVertex2d(xLeft + WIDTH, yUp);
    glVertex2d(xLeft + WIDTH, yUp - HEIGTH);
    glVertex2d(xLeft, yUp - HEIGTH);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0, 0, 0, 1);
    glVertex2d(xLeft + WIDTH - 0.01, yUp);
    glVertex2d(xLeft + WIDTH, yUp);
    glVertex2d(xLeft + WIDTH, yUp - HEIGTH);
    glVertex2d(xLeft+ WIDTH - 0.01, yUp - HEIGTH);
    glEnd();

    // draw button_name
    glColor3f(1, 1, 1);
    glRasterPos2f(xLeft, yUp - HEIGTH * 3 / 4);
    for (int i = 0; i < length; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[i]);
} // end of draw function

void button_cl::init(fstream &stream)
{
  string curStr;
  float xLeft;
  float yUp;

  stream >> curStr;
    while (!stream.eof() && curStr != "ButtonEnd")
    {
      if (curStr == "Position")
      {
        stream >> xLeft;
        stream >> yUp;
        pos.init(xLeft, yUp);
      }
      else if (curStr == "Color")
      {
        float r, g, b;
        stream >> r;
        stream >> g;
        stream >> b;
        color.color_init(r, g, b, 1);
      }
      else if (curStr == "HightColor")
      {
        float r, g, b;
        stream >> r;
        stream >> g;
        stream >> b;
        hightColor.color_init(r, g, b, 1);
      }
      else if (curStr == "Name")
      {
         stream >> name;
      }
      else
      {
        cout << "ERROR:(button_cl.cpp, init func)incorrect menu file" << endl;
        break;
      }
      stream >> curStr;
    }
    state = false;
} // end of init function

bool button_cl::in_button(float x, float y)
{
  float xLeft = pos.get_x();
  float yUp = pos.get_y();

  if (x >= xLeft && x <= xLeft + WIDTH)
    if (y <= yUp && y >= yUp - HEIGTH)
      return true;
  return false;
} // end of in_button func

paint_mode_t button_cl::action()
{
  if (name == "exit")
    return my_exit;
  else if (name == "rubber")
    return my_rubber;
  else if (name == "brush")
    return my_brush;
  else if (name == "clear")
    return my_clear;
  else if (name == "change_r")
    return my_change_r;
  else if (name == "pallete")
    return my_pallete;
  else
    return my_passive;
} // end of action func
