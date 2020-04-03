#ifndef COLOR_CL_H
#define COLOR_CL_H
// leins, 23.05.2018

enum paint_mode_t
{
  my_passive,
  my_pallete,
  my_brush,
  my_rubber,
  my_exit,
  my_change_r,
  my_clear
};

class color_cl
{
private:
  float A;
  float R;
  float G;
  float B;

public:
  void color_init(float r, float g, float b, float a)
  {
    R = r;
    G = g;
    B = b;
    A = a;
  }
  void change_alpha(float delta)
  {
    A -= delta;
  }
  float get_a() { return A; }
  float get_r() { return R; }
  float get_g() { return G; }
  float get_b() { return B; }
};


#endif // COLOR_CL_H
