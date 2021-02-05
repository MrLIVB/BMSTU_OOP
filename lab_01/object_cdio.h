#ifndef OBJECT_CDIO_H
#define OBJECT_CDIO_H

#include "my_string.h"
#include "point_cdio.h"
#include "point.h"
#include "edges.h"

#include <QGraphicsView>

struct model_t
{
    int points_c;
    point_t *points;
    int **edges;
    point_t center;
};

results get_points_c(int &points_c, FILE *in);

results find_center(point_t &center_res, point_t *points, int &points_c);

model_t init_model();

results allocate_model(model_t &model);

results delete_model(model_t &model);

results copy_model(model_t &to, model_t &from);

results transfer_model(model_t &to, model_t &from);

results read_model(model_t &model, FILE *in);

#endif // OBJECT_CDIO_H
