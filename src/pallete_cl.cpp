// leins, 23.05.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include "pallete_cl.h"

void pallete_cl::init(float x, float y)
{
  float tmp = 1. / (COLORS + 2);
  float x1 = x + 0.01;
  float y1 = y + 0.005;

  pos.init(x, y);
  for (int i = 0; i < COLORS; i++)
  {
    cell_cl newCell;
    point_cl pos1;
    color_cl color;

    color.color_init(0, tmp, 1, 1);
    pos1.init(x1, y1);
    x1 += W;
    tmp += tmp;
    newCell.init(color, pos1);
    cells.push_back(newCell);
  }
} // end of init func

void pallete_cl::draw()
{
  /*
  float xLeft = pos.get_x();
  float yUp = pos.get_y();
  float WIDTH = 0.02 + W * COLORS;
  float HEIGTH = 0.01 + H;

  glBegin(GL_QUADS);
  glColor4f(0.7, 0.7, 0.7, 1);
  glVertex2d(xLeft, yUp);
  glVertex2d(xLeft + WIDTH, yUp);
  glVertex2d(xLeft + WIDTH, yUp - HEIGTH);
  glVertex2d(xLeft+ WIDTH, yUp - HEIGTH);
  glEnd();
  */

  for (auto it : cells)
  {
    it.draw();
  }

}// end of func

color_cl pallete_cl::process(float x, float y)
{
  color_cl col;

  col.color_init(0, 0, 0, 1);
  for (auto it : cells)
  {
    if (it.in_cell(x, y))
      col = it.get_color();
  }

  return col;
}// end of func
