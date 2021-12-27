typedef struct Node{
    char *word;
    struct Node *left;
    struct Node *right;
} NODE;

extern NODE *root;

void insert_node(char *w);

void print_tree(NODE *r);