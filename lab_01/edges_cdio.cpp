#include "edges.h"

results get_edges_c(int &c, FILE *in)
{
    results res = ok;
    if (fscanf(in, "%d", &c) != 1 || c < 1)
        res = incorrect_format;
    return res;
}

results read_edge(int **matrix, int &points_c, FILE *in)
{
    int a, b;
    if (fscanf(in, "%d%d", &a, &b) != 2 || a < 0 || b < 0 \
            || a > points_c || b > points_c)
        return incorrect_format;
    matrix[a][b] = 1;
    return ok;
}

results read_edges(int **matrix, int &points_c, FILE *in) // подавать только нужное
{
    if (!matrix)
        return not_initialized;

    int n;
    results res = ok;
    res = get_edges_c(n, in);
    for (int i = 0; i < n && res == ok; i++)
        res = read_edge(matrix, points_c, in);

    return res;
}
