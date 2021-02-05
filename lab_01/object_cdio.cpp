#include "object_cdio.h"

results find_center(point_t &center_res, point_t *points, int &points_c)
{
    if (!points)
        return not_initialized;

    point_t center, res_max, res_min;

    copy_point(res_max, points[0]);
    copy_point(res_min, points[0]);

    for (int i = 1; i < points_c; i++)
    {
        compare_point(res_max, points[i], 1);
        compare_point(res_min, points[i], 0);
    }
    center.x = (res_max.x + res_min.x) / 2;
    center.y = (res_max.y + res_min.y) / 2;
    center.z = (res_max.z + res_min.z) / 2;

    center_res = center;
    return ok;
}

results get_points_c(int &points_c, FILE *in)
{
    int a = 0;
    if (fscanf(in, "%d", &a) != 1  || a <= 0)
        return incorrect_format;
    points_c = a;
    return ok;
}

model_t init_model()
{
    model_t figure;
    figure.points = NULL;
    figure.points_c = 0;
    point_t center;
    center.x = 0;
    center.y = 0;
    center.z = 0;
    figure.center = center;
    figure.edges = NULL;
    return figure;
}

results allocate_model(model_t &model)
{
    model.points = (point_t*)malloc(sizeof(point_t) * model.points_c);
    if (model.points == NULL)
        return cant_allocate;

    model.edges = (int**)malloc(sizeof(int*) * model.points_c);
    for (int i = 0; i < model.points_c; i++)
        model.edges[i] = (int*)calloc(model.points_c, sizeof(int));

    return ok;
}

results delete_model(model_t &model)
{
    if (model.points_c == 0)
        return ok;
    if (model.points)
        free(model.points);

    for (int i = 0; i < model.points_c; i++)
        if (model.edges[i])
            free(model.edges[i]);
    if (model.edges)
        free(model.edges);

    model.points = NULL;
    model.edges = NULL;
    return ok;
}

results transfer_model(model_t &to, model_t &from)
{
    copy_point(to.center, from.center);

    to.points_c = from.points_c;

    to.points = from.points;
    from.points = NULL;

    to.edges = from.edges;
    from.edges = NULL;
    return ok;
}

results read_model(model_t &model, FILE *in)
{
    results res = read_points(model.points, model.points_c, in);
    if (res == ok)
        res = read_edges(model.edges, model.points_c, in);
    return res;
}
