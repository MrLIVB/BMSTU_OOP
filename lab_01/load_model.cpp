#include "load_model.h"

results load_model_text_file(model_t &model, FILE *in)
{
    results res = get_points_c(model.points_c, in);
    if (res == ok){
        res = allocate_model(model);
        if (res == ok){
            res = read_model(model, in);
            if (res == ok)
                find_center(model.center, model.points, model.points_c);
            else
                delete_model(model);
        }
    }
    return res;
}

results load_model(model_t &model, my_string &filename)
{
    FILE *in = fopen(qstr_to_cstr(filename), "r");
    if (in == NULL)
        return no_file;

    model_t temp_model = init_model();

    results res = load_model_text_file(temp_model, in);
    fclose(in);
    if (res == ok)
    {
        delete_model(model);
        transfer_model(model, temp_model);
    }
    return res;
}
