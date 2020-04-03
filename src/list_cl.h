#pragma once
#ifndef LIST_CL_H
#define LIST_CL_H

// leins, 17.04.2018
#include <vector>
#include <string>
#include "button_cl.h"

enum side_t
{
    down,
    my_right
};

class list_cl
{
private:
    std::vector<button_cl> list;
    side_t side;

public:
    void disable();
    void draw();
    void init(std::string fileName);
    void clear_list();
    void set_active(int n);
    // void passive(float x, float y);
    paint_mode_t action(float x, float y);
    bool is_active();
};

#endif // LIST_CL_H
