#include "object.h"

using namespace std;

results move_model(model_t &model, vector_t &transfrom)
{
    if (model.points_c == 0 || !model.points)
        return no_model;
    for (int i = 0; i < model.points_c; i++)
        move_pnt(model.points[i], transfrom);
    move_pnt(model.center, transfrom);
    return ok;
}

results scale_model(model_t &model, vector_t &transform)
{
    if (model.points_c == 0 || !model.points)
        return no_model;
    for (int i = 0; i < model.points_c; i++)
        scale_pnt(model.points[i], model.center, transform);
    return ok;
}

float rad(int angle)
{
    return angle * M_PI / 180.;
}

results rotate_model(model_t &model, vector_t &transform)
{
    if (model.points_c == 0 || !model.points)
        return no_model;

    transform.x = rad(transform.x);
    transform.y = rad(transform.y);
    transform.z = rad(transform.z);

    move_points_to(model.points, model.points_c, model.center);
    rotate_points(model.points, model.points_c, transform);
    move_points_from(model.points, model.points_c, model.center);
    return ok;
}
