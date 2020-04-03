// leins, 22.05.2018

#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include "glut_callbacks.h"
#include "list_cl.h"
#include "paint_cl.h"

using namespace std;

list_cl g_menu_list;
paint_cl g_paint;

int main(int argc, char *argv[])
{
  g_menu_list.init("paint_menu.txt");
  g_paint.init();

  // glut begin
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(WIN_W, WIN_H);
  glutCreateWindow("paint");

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutMouseFunc(Mouse);
  glutMotionFunc(Motion);
  // glutPassiveMotionFunc(PassiveMotion);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glutMainLoop();
  // glut end

  return 0;
}// end of main
