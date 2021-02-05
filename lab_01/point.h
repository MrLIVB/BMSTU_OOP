#ifndef  POINT_H
#define POINT_H

#include <cmath>
#include "point_cdio.h"

struct vector_t{
    float x;
    float y;
    float z;
};

int move_pnt(point_t &point, vector_t &shift);

int scale_pnt(point_t &point, point_t center, vector_t &shift);

point_t project_point(point_t &p, point_t &view_point);

int rotate_points(point_t *points, int points_c, vector_t &rot);

int move_points_to(point_t *points, int &points_c, point_t &center);

int move_points_from(point_t *points, int &points_c, point_t &center);

int compare_point(point_t &res, point_t &check, int max);

#endif // ! POINT_H
