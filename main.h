#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

#define RED   0
#define BLACK 1

typedef int data_t;

typedef struct node
{
    data_t data;
    int color;

    struct node *left;
    struct node *right;
    struct node *parent;

} tree_t;

/* Red-Black Tree operations */

int insert(tree_t **root, data_t item);
int delete(tree_t **root, data_t item);
int search(tree_t *root, data_t item);
int find_minimum(tree_t **root, data_t *min);
int find_maximum(tree_t **root, data_t *max);
int delete_minimum(tree_t **root);
int delete_maximum(tree_t **root);

/* Red-Black Tree balancing */

void insert_fixup(tree_t **root, tree_t *new_node);
void left_rotate(tree_t **root, tree_t *x);
void right_rotate(tree_t **root, tree_t *x);
void delete_fixup(tree_t **root, tree_t *x, tree_t *parent);

/* Display */
void inorder(tree_t *root);

/* Input validation */
int read_integer(data_t *num);

#endif