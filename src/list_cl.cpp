// leins 25.04.2018

#include <iostream>
#include <cstring>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include "list_cl.h"

using namespace std;

void list_cl::set_active(int n)
{
  list.at(n).change_state();
}

void list_cl::draw()
{
  glBegin(GL_QUADS);
  glColor4f(0.3, 0.3, 0.3, 1);
  glVertex2d(-1, 1);
  glVertex2d(1, 1);
  glVertex2d(1, 1 - HEIGTH);
  glVertex2d(-1, 1 - HEIGTH);
  glEnd();

  for (auto it : list)
  {
    it.draw();
  }
}

void list_cl::disable()
{
  for (auto &it : list)
    if (it.get_state())
      it.change_state();
}

void list_cl::init(string fileName)
{
  string curStr;
  string sideName;
  fstream stream;

  stream.open(fileName);
  if (!stream.is_open())
  {
    cout << "ERROR:(list_cl.cpp init function) - cannot open file" << endl;
  }
  else
  {
    this->clear_list();
    stream >> curStr;
    if (curStr != "ListBegin")
      cout << "ERROR:(list_cl.cpp init function) - incorrect file" << endl;
    else
    {
      stream >> curStr;
      if (curStr == "Side")
        stream >> sideName;
      else
        cout << "ERROR:(list_cl.cpp init function) -unknown menu operation" << endl;

      if (sideName == "down")
        side = down;
      else
        side = my_right;

      stream >> curStr;
      while (!stream.eof() && curStr != "ListEnd")
      {
        if (curStr == "ButtonBegin")
        {
          button_cl button;
          button.init(stream);
          list.push_back(button);
        }
        else
        {
          cout << "ERROR:(list_cl.cpp init function) - unknown menu file" << endl;
          break;
        }
        stream >> curStr;
      }
    }
  }
}

/*
void list_cl::passive(float x, float y)
{
    for (auto& it : list)
    {
      // choose new active
      if (it.in_button(x, y) && it.get_state() == false)
        it.change_state();
      // disable last active
      if (!it.in_button(x, y) && it.get_state() == true)
        it.change_state();
    }
} // end of passive function
*/

void list_cl::clear_list()
{
  while (!list.empty())
    list.pop_back();
} // end of clear list

bool list_cl::is_active()
{
  bool ans = false;

  for (auto it : list)
    if (it.get_state())
      ans = true;
  return ans;
} // end

paint_mode_t list_cl::action(float x, float y)
{
  paint_mode_t m;

  for (auto &it : list)
  {
    if (it.in_button(x, y))
    {
      m = it.action();
      if (it.get_name() != "change_r")
      it.change_state();
    }
    else
    {
      if (it.get_state())
        it.change_state();
    }
  }
  return m;
} // end of action func
