#include "point.h"

int move_pnt(point_t &point, vector_t &shift)
{
    point.x += shift.x;
    point.y += shift.y;
    point.z += shift.z;
    return 0;
}

int scale_pnt(point_t &point, point_t center, vector_t &shift)
{
    point.x = point.x * shift.x + (1 - shift.x) * center.x;
    point.y = point.y * shift.y + (1 - shift.y) * center.y;
    point.z = point.z * shift.z + (1 - shift.y) * center.z;
    return 0;
}

int rotate_ox_pnt(point_t &point, float cosa, float sina)
{
    float y = point.y * cosa - point.z * sina;
    float z = point.y * sina + point.z * cosa;
    point.y = y;
    point.z = z;
    return 0;
}

int rotate_oy_pnt(point_t &point, float cosa, float sina)
{
    float x = point.x * cosa + point.z * sina;
    float z = -point.x * sina + point.z * cosa;
    point.x = x;
    point.z = z;
    return 0;
}

int rotate_oz_pnt(point_t &point, float cosa, float sina)
{
    float x = point.x * cosa - point.y * sina;
    float y = point.x * sina + point.y * cosa;
    point.x = x;
    point.y = y;
    return 0;
}

int rotate_points(point_t *points, int points_c, vector_t &rot)
{
    float cosx = cos(rot.x);
    float sinx = sin(rot.x);

    float cosy = cos(rot.y);
    float siny = sin(rot.y);

    float cosz = cos(rot.z);
    float sinz = sin(rot.z);

    for (int i = 0; i < points_c; i++){
        rotate_ox_pnt(points[i], cosx, sinx);
        rotate_oy_pnt(points[i], cosy, siny);
        rotate_oz_pnt(points[i], cosz, sinz);
    }
    return 0;
}

int move_points_to(point_t *points, int &points_c, point_t &center)
{
    vector_t shift;
    shift.x = -center.x;
    shift.y = -center.y;
    shift.z = -center.z;
    for (int i = 0; i < points_c; i++)
        move_pnt(points[i], shift);
    return 0;
}

int move_points_from(point_t *points, int &points_c, point_t &center)
{
    vector_t shift;
    shift.x = center.x;
    shift.y = center.y;
    shift.z = center.z;
    for (int i = 0; i < points_c; i++)
        move_pnt(points[i], shift);
    return 0;
}

int compare_point(point_t &res, point_t &check, int max)
{
    if (max)
    {
        if (res.x < check.x)
            res.x = check.x;
        if (res.y < check.y)
            res.y = check.y;
        if (res.z < check.z)
            res.z = check.z;
    }
    else
    {
        if (res.x > check.x)
            res.x = check.x;
        if (res.y > check.y)
            res.y = check.y;
        if (res.z > check.z)
            res.z = check.z;
    }
    return 0;
}

point_t project_point(point_t &p, point_t &view_point)
{
    point_t res;
    res.x = view_point.z * p.x / (p.z + view_point.z);
    res.y = view_point.z * p.y / (p.z + view_point.z);
    res.z = 0;
    return res;
}
