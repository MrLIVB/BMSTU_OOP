#include "draw_model.h"

// Разбить на разные модули

int draw_line(point_t &p1, point_t &p2, point_t &view_point, my_painter_t &canvas)
{
    point_t t1 = project_point(p1, view_point);
    point_t t2 = project_point(p2, view_point);

    my_draw_line(t1, t2, canvas);
    return 0;
}

int draw_edges(int point, model_t &model, point_t &view_point, my_painter_t &canvas)
{
    for (int i = point; i < model.points_c; i++)
        if (model.edges[point][i])
            draw_line(model.points[point], model.points[i], view_point, canvas);

    return 0;
}

results draw_object(model_t &model, point_t &view_point, my_painter_t &canvas)
{
    my_clear(canvas);
    for (int i = 0; i < model.points_c; i++)
        draw_edges(i, model, view_point, canvas);
    return ok;
}
