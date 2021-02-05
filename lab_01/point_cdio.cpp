#include "point_cdio.h"

int copy_point(point_t &in, point_t &from)
{
    in.x = from.x;
    in.y = from.y;
    in.z = from.z;
    return 0;
}

int create_point(point_t &point)
{
    point.x = 0;
    point.y = 0;
    point.z = 0;
    return 0;
}

results read_point(point_t &point, FILE *in)
{
    float x, y, z;

    if ((fscanf(in, "%f%f%f", &x, &y, &z) != 3))
        return incorrect_format;

    point.x = x;
    point.y = y;
    point.z = z;

    return ok;
}

results read_points(point_t *points, int &points_c, FILE *in)
{
    if (!points)
        return not_initialized;
    results res = ok;
    for (int i = 0; i < points_c && res == ok; i++)
        res = read_point(points[i], in);
    return res;
}
