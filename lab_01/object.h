#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "object_cdio.h"
#include "my_string.h"
#include "point.h"

using namespace std;

typedef int rotate[3][3];

results move_model(model_t &model, vector_t &transform);

results scale_model(model_t &model, vector_t &transform);

float rad(int angle);

results rotate_model(model_t &model, vector_t &transform);

#endif // !OBJECT_H
