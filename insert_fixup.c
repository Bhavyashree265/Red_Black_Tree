#include "main.h"

void insert_fixup(tree_t **root, tree_t *new_node)
{
    tree_t *parent;
    tree_t *grandparent;
    tree_t *uncle;

    while (new_node != *root && new_node->parent->color == RED)
    {
        parent = new_node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left)
        {
            uncle = grandparent->right;
            
            /* Case 1: Uncle is RED (recolor) */
            if (uncle != NULL && uncle->color == RED)
            {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                new_node = grandparent;
            }
            else
            {
                /* Case 2: rotate and recolor*/
                if (new_node == parent->right)
                {
                    left_rotate(root, parent);

                    new_node = parent;
                    parent = new_node->parent;
                }

                /* Case 3: Line */
                right_rotate(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        }
        else
        {
            uncle = grandparent->left;

            /* Case 1: Uncle is RED(recolor) */
            if (uncle != NULL && uncle->color == RED)
            {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                new_node = grandparent;
            }
            else
            {
                /* Case 2: Triangle(rotate and recolor) */
                if (new_node == parent->left)
                {
                    right_rotate(root, parent);
                    new_node = parent;
                    parent = new_node->parent;
                }

                /* Case 3: Line */
                left_rotate(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        }
    }

    /* Root must always be BLACK */
    (*root)->color = BLACK;
}