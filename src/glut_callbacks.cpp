// leins, 13.05.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include "glut_callbacks.h"
#include "list_cl.h"
#include "paint_cl.h"

using namespace std;

// global variables used in callbacks functions
extern list_cl g_menu_list;
extern paint_cl g_paint;

void Keyboard(unsigned char key, int x, int y)
{
  if (key == 27)
    exit(0);
}// End of Keyboard function

void Display(void)
{
  if (g_paint.get_mode() == my_clear)
  {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    g_paint.set_mode(my_passive);
    g_menu_list.action(0, 0);
  }

  g_menu_list.draw();
  g_paint.process();

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}// End of Display function

void Mouse(int button, int state, int x, int y)
{  
  float x1 = float(x) / WIN_W * 2 - 1;
  float y1 = -float(y) / WIN_H * 2 + 1;

  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN)
    {
      if (y1 >= 1 - HEIGTH)
        g_paint.set_mode(g_menu_list.action(x1, y1));
      if (g_paint.get_mode() == my_pallete)
        g_paint.change_color(g_paint.get_color(x1, y1));
    }
} // end of Mouse function

void Motion(int x, int y)
{
  float x1 = float(x) / WIN_W * 2 - 1;
  float y1 = -float(y) / WIN_H * 2 + 1;

  if (g_paint.get_mode() == my_brush || g_paint.get_mode() == my_rubber)
    g_paint.draw(x1, y1);
}

