// leins, 23.05.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include "cell_cl.h"

void cell_cl::init(color_cl nColor, point_cl nPos)
{
  color = nColor;
  pos = nPos;
}

void cell_cl::draw()
{
  glBegin(GL_QUADS);
  glColor4f(color.get_r(), color.get_g(), color.get_b(), color.get_a());
  glVertex2d(pos.get_x(), pos.get_y());
  glVertex2d(pos.get_x() + W, pos.get_y());
  glVertex2d(pos.get_x() + W, pos.get_y() - H);
  glVertex2d(pos.get_x(), pos.get_y() - H);
  glEnd();
}

bool cell_cl::in_cell(float x, float y)
{
  float xLeft = pos.get_x();
  float yUp = pos.get_y();

  if (x >= xLeft && x <= xLeft + W)
    if (y <= yUp && y >= yUp - H)
      return true;
  return false;
} // eof
