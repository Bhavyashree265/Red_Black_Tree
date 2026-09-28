#include "main.h"

static void print_inorder(tree_t *root);
static void print_tree(tree_t *root, const char *prefix, int is_left)
{
    char new_prefix[100];
    if (root == NULL)
    {
        return;
    }
    printf("%s", prefix);

    if (is_left)
    {
        printf("├── L: ");
    }
    else
    {
        printf("└── R: ");
    }
    printf("%d(%s)\n",root->data,root->color == RED ? "R" : "B");
    snprintf(new_prefix, sizeof(new_prefix),"%s%s",prefix,is_left ? "│   " : "    ");

    print_tree(root->left, new_prefix, 1);
    print_tree(root->right, new_prefix, 0);
}

void inorder(tree_t *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    printf("\nRoot: %d(%s)\n",root->data,root->color == RED ? "R" : "B");
    printf("\nTree:\n");

    printf("%d(%s)\n",root->data,root->color == RED ? "R" : "B");

    print_tree(root->left, "", 1);
    print_tree(root->right, "", 0);

    printf("\nInorder: ");
    print_inorder(root);
    printf("\n");
}

static void print_inorder(tree_t *root)
{
    if (root == NULL)
    {
        return;
    }

    print_inorder(root->left);

    printf("%d(%s) ",root->data,root->color == RED ? "R" : "B");
    print_inorder(root->right);
}