#include "main.h"

/* Delete a node from Red-Black Tree */
int delete(tree_t **root, data_t item)
{
    tree_t *temp;
    tree_t *successor;
    tree_t *child;
    tree_t *parent;

    /* Tree is empty */
    if (*root == NULL)
    {
        return FAILURE;
    }
    temp = *root;

    /* Search for the node */
    while (temp != NULL)
    {
        if (item < temp->data)
        {
            temp = temp->left;
        }
        else if (item > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            break;
        }
    }

    /* Node not found */
    if (temp == NULL)
    {
        return FAILURE;
    }

    int deleted_color = temp->color;
    parent = temp->parent;

    /* Node has no left child */
    if (temp->left == NULL)
    {
        child = temp->right;
    }

    /* Node has no right child */
    else if (temp->right == NULL)
    {
        child = temp->left;
    }

    /* Node has two children */
    else
    {
        successor = temp->right;

        while (successor->left != NULL)
        {
            successor = successor->left;
        }

        /* Copy successor data */
        temp->data = successor->data;

        temp = successor;

        parent = temp->parent;
        deleted_color = temp->color;
        child = temp->right;
    }

    /* Node is root */
    if (parent == NULL)
    {
        *root = child;
        if (child != NULL)
        {
            child->parent = NULL;
        }
    }

    /* Node is left child */
    else if (temp == parent->left)
    {
        parent->left = child;

        if (child != NULL)
        {
            child->parent = parent;
        }
    }

    /* Node is right child */
    else
    {
        parent->right = child;
        if (child != NULL)
        {
            child->parent = parent;
        }
    }

    free(temp);

    /* Fix Red-Black Tree if a BLACK node was deleted */
    if (deleted_color == BLACK)
    {
        if (*root != NULL)
        {
            delete_fixup(root, child, parent);
        }
    }

    return SUCCESS;
}