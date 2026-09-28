#include "main.h"

void delete_fixup(tree_t **root, tree_t *x, tree_t *parent)
{
    tree_t *sibling;

    while (x != *root && (x == NULL || x->color == BLACK))
    {
        if (parent == NULL)
        {
            break;
        }

        if (x == parent->left)
        {
            sibling = parent->right;

            /* Case 1: sibling is RED */
            if (sibling != NULL && sibling->color == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;

                left_rotate(root, parent);

                sibling = parent->right;
            }

            /* Case 2: sibling is BLACK and both children are BLACK */
            if (sibling == NULL ||
                ((sibling->left == NULL || sibling->left->color == BLACK) &&
                 (sibling->right == NULL || sibling->right->color == BLACK)))
            {
                if (sibling != NULL)
                {
                    sibling->color = RED;
                }

                x = parent;
                parent = x->parent;
            }

            /* Case 3: sibling is BLACK,
               near child is RED,
               far child is BLACK */
            else if (sibling->right == NULL ||
                     sibling->right->color == BLACK)
            {
                if (sibling->left != NULL)
                {
                    sibling->left->color = BLACK;
                }

                sibling->color = RED;

                right_rotate(root, sibling);

                sibling = parent->right;
            }

            /* Case 4: sibling is BLACK and far child is RED */
            else
            {
                sibling->color = parent->color;
                parent->color = BLACK;

                if (sibling->right != NULL)
                {
                    sibling->right->color = BLACK;
                }

                left_rotate(root, parent);

                x = *root;
                parent = NULL;
            }
        }
        else
        {
            sibling = parent->left;

            /* Case 1: sibling is RED */
            if (sibling != NULL && sibling->color == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;

                right_rotate(root, parent);

                sibling = parent->left;
            }

            /* Case 2: sibling is BLACK and both children are BLACK */
            if (sibling == NULL ||
                ((sibling->left == NULL || sibling->left->color == BLACK) &&
                 (sibling->right == NULL || sibling->right->color == BLACK)))
            {
                if (sibling != NULL)
                {
                    sibling->color = RED;
                }

                x = parent;
                parent = x->parent;
            }

            /* Case 3: sibling is BLACK,
               near child is RED,
               far child is BLACK */
            else if (sibling->left == NULL ||
                     sibling->left->color == BLACK)
            {
                if (sibling->right != NULL)
                {
                    sibling->right->color = BLACK;
                }

                sibling->color = RED;

                left_rotate(root, sibling);

                sibling = parent->left;
            }

            /* Case 4: sibling is BLACK and far child is RED */
            else
            {
                sibling->color = parent->color;
                parent->color = BLACK;

                if (sibling->left != NULL)
                {
                    sibling->left->color = BLACK;
                }

                right_rotate(root, parent);

                x = *root;
                parent = NULL;
            }
        }
    }

    if (x != NULL)
    {
        x->color = BLACK;
    }
}