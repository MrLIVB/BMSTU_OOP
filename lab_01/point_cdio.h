#ifndef POINT_CDIO_H
#define POINT_CDIO_H

#include <iostream>

enum results{ok, no_file, empty_file, no_model, not_initialized, incorrect_format, incorrect_action, cant_allocate};

struct point_t
{
    float x;
    float y;
    float z;
};


int copy_point(point_t &in, point_t &from);

results delete_point(point_t &point);

results read_point(point_t &point, FILE *in);

results read_points(point_t *points, int &points_c, FILE *in);

#endif // POINT_CDIO_H
