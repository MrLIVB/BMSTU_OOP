#ifndef DRAW_MODEL_H
#define DRAW_MODEL_H

#include "my_draw.h"

struct canvas_t{
    point_t view_point;
    my_painter_t scene;
};

results draw_object(model_t &model, point_t &view_point, my_painter_t &canvas);

#endif // DRAW_MODEL_H
