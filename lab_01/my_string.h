#ifndef MY_STRING_H
#define MY_STRING_H

#include <QString>

struct my_string{
    QString string;
};

const char *qstr_to_cstr(my_string &string);

#endif // MY_STRING_H
