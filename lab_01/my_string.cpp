#include "my_string.h"

const char *qstr_to_cstr(my_string &string)
{
    return string.string.toStdString().c_str();
}
