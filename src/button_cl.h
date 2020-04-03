#pragma once
#ifndef BUTTON_CL_H
#define BUTTON_CL_H
// leins, 18.04.2018

#include <fstream>
#include <string>
#include "color_cl.h"
#include "point_cl.h"

#define HEIGTH 0.04
#define WIDTH 0.3

class button_cl
{
private:
    point_cl pos; // left up coner
    std::string name;
    color_cl color;
    color_cl hightColor;
    bool state;

public:
    bool get_state() { return state; }
    std::string get_name() { return name; }

    paint_mode_t action();
    void draw();
    void init(std::fstream &stream);
    void change_state();
    bool in_button(float x, float y);

};

#endif
