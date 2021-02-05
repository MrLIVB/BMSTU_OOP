#ifndef CORE_FUNC_H
#define CORE_FUNC_H

#include <QGraphicsView>
#include "draw_model.h"
#include "object.h"

#include "load_model.h"

enum actions{start_a, rotate_a, move_a, scale_a, paint_a, delete_a};

struct data_t{
    my_string filename;
    vector_t transform;
};

results core(canvas_t &scene, data_t &params, actions action);

#endif // CORE_FUNC_H
