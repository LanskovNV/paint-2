#ifndef BRUSH_CL_H
#define BRUSH_CL_H
// leins, 23.05.2018

#include "point_cl.h"
#include "color_cl.h"

#define RAD 0.01

class brush_cl
{
private:
  color_cl color;
  float radius;

public:
  void draw(float x, float y);
  void set_color(color_cl c) {color = c;}
  void init(float nRad, color_cl nColor);
  void change_color(color_cl nColor) { color = nColor; }
  void change_rad(float nRad) { radius = nRad; }
  float get_radius() { return radius; }
  color_cl get_color() { return color; }
};

#endif // BRUSH_CL_H
