#include "main.h"

/* Inserting a node */
int insert(tree_t **root, data_t item)
{
    /* Create a new node using DMA */
    tree_t *new_node = malloc(sizeof(tree_t));

    if (new_node == NULL)
    {
        return FAILURE;
    }

    /* Initialize the new node */
    new_node->data = item;
    new_node->color = RED;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;

    /* Empty tree */
    if (*root == NULL)
    {
        new_node->color = BLACK;
        *root = new_node;

        return SUCCESS;
    }

    /* Non-empty tree */
    tree_t *current = *root;
    tree_t *parent = NULL;

    /* Find the correct position */
    while (current != NULL)
    {
        parent = current;

        if (item < current->data)
        {
            current = current->left;
        }
        else if (item > current->data)
        {
            current = current->right;
        }
        else
        {
            /* Duplicate value */
            free(new_node);
            return FAILURE;
        }
    }

    /* Connect new node with its parent */
    new_node->parent = parent;

    if (item < parent->data)
    {
        parent->left = new_node;
    }
    else
    {
        parent->right = new_node;
    }

    /* Restore Red-Black Tree properties */
    insert_fixup(root, new_node);

    return SUCCESS;
}