#include "core_func.h"

results core(canvas_t &scene, data_t &params, actions action)
{
    static model_t figure = init_model();
    results rc = ok;

    if (action == start_a)
        rc = load_model(figure, params.filename);
    else if (action == rotate_a)
        rc = rotate_model(figure, params.transform);
    else if (action == move_a)
        rc = move_model(figure, params.transform);
    else if (action == scale_a)
        rc = scale_model(figure, params.transform);
    else if (action == paint_a)
        rc = draw_object(figure, scene.view_point, scene.scene);
    else if (action == delete_a)
        rc = delete_model(figure);
    else
        rc = incorrect_action;
    return rc;
}
