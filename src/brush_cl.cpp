// leins, 23.05.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include "brush_cl.h"

void brush_cl::draw(float x, float y)
{
  float i;
  const float sepCnt = 10;
  const float pi = 3.14159265;

  glColor4f(color.get_r(), color.get_g(), color.get_b(), color.get_a());

  glBegin(GL_TRIANGLE_FAN);
  glVertex2d(x, y);
  for (i = 0; i < sepCnt; i++)
  {
    float angl = i / (sepCnt - 1) * 2.0 * pi;
    glVertex2d(x + radius * cos(angl), y + radius * sin(angl));
  }
  glEnd();
} // end of draw func

void brush_cl::init(float nRad, color_cl nColor)
{
  radius = nRad;
  color = nColor;
}
