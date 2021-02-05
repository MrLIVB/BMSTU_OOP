#include "my_draw.h"

int my_draw_line(point_t &p1, point_t &p2, my_painter_t &canvas)
{
    canvas.scene->addLine(p1.x, p1.y, p2.x, p2.y, QPen(Qt::black, 2));
    return 0;
}

int my_get_width(my_painter_t &canvas)
{
    return canvas.scene->width();
}

int my_get_height(my_painter_t &canvas)
{
    return canvas.scene->height();
}

int my_clear(my_painter_t &canvas)
{
    canvas.scene->clear();
    return 0;
}
