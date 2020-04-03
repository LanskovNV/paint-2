#ifndef PALLETE_CL_H
#define PALLETE_CL_H

// leins, 23.05.2018

#include <vector>
#include "cell_cl.h"

#define COLORS 5

class pallete_cl
{
private:
  point_cl pos;
  std::vector<cell_cl> cells;

public:
  void init(float x, float y);
  void draw();
  color_cl process(float x, float y);
};

#endif // PALLETE_CL_H
