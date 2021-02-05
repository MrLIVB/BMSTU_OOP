#ifndef LOAD_MODEL_H
#define LOAD_MODEL_H

#include "object_cdio.h"

results load_model_text_file(model_t &model, FILE *in);

results load_model(model_t &model, my_string &filename);

#endif // LOAD_MODEL_H
