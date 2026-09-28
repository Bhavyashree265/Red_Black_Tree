#include "main.h"

int search(tree_t *root, data_t item)
{
    tree_t *temp = root;
    while (temp != NULL)
    {
        if (item == temp->data)
            return SUCCESS;

        if (item < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return FAILURE;
}