#ifndef CELL_CL_H
#define CELL_CL_H
// leins, 23.05.2018

#include "color_cl.h"
#include "point_cl.h"

#define W 0.08
#define H 0.08

class cell_cl
{
private:
  color_cl color;
  point_cl pos;
public:
  color_cl get_color() {return color;}
  void init(color_cl nColor, point_cl nPos);
  bool in_cell(float x, float y);
  void draw();
};

#endif // CELL_CL_H
