#ifndef MY_DRAW_H
#define MY_DRAW_H

#include <QGraphicsView>
#include "object.h"

struct my_painter_t{
    QGraphicsScene *scene;
};

int my_draw_line(point_t &p1, point_t &p2, my_painter_t &canvas);

int my_get_width(my_painter_t &canvas);

int my_get_height(my_painter_t &canvas);

int my_clear(my_painter_t &canvas);

#endif // MY_DRAW_H
