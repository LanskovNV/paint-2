#ifndef PAINT_CL_H
#define PAINT_CL_H

#include "brush_cl.h"
#include "pallete_cl.h"

class paint_cl
{
private:
  paint_mode_t mode;
  brush_cl brush;
  brush_cl rubber;

pallete_cl pallete;

public:
  void process();
  void init();
  void change_r(float r);
  void change_color(color_cl nColor) { brush.set_color(nColor); }
  void set_mode(paint_mode_t newMode);
  void draw(float x, float y);
  paint_mode_t get_mode() { return mode; }
  void current_info();
  color_cl get_color(float x, float y);
};

#endif // PAINT_CL_H
