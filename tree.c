#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tree.h"

NODE *root = NULL;

void rec_insert_node (NODE *n, NODE *r) {
    int n_r_comp = strcmp(n->word, r->word);
    if (n_r_comp < 0) {
        if (r->left == 0) {
            r->left = n;
        }
        else {
            rec_insert_node(n,r->left);
        }
    }
    else {
        if (r->right == 0) {
            r->right = n;
        }
        else {
            rec_insert_node(n,r->right);
        }
    }
}

void insert_node(char *w) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->word = w;
    if (root != 0) {
        rec_insert_node(new_node, root);
    }
    else {
        root = new_node;
    }
}

void print_tree(NODE *r) {
    if (r == 0) {
        return;
    }
    else {
        print_tree(r->left);
        printf("%s\n", r->word);
        print_tree(r->right);
    }
}