#include "main.h"

int delete_minimum(tree_t **root)
{
    data_t min;

    if (find_minimum(root, &min) == FAILURE)
    {
        return FAILURE;
    }

    return delete(root, min);
}

int delete_maximum(tree_t **root)
{
    data_t max;

    if (find_maximum(root, &max) == FAILURE)
    {
        return FAILURE;
    }

    return delete(root, max);
}