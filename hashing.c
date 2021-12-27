#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "tree.h"

#define SIZE 100

typedef struct cell{
    char *word;
    struct cell *next;
}HASHCELL; 

HASHCELL *hashtable[SIZE];

unsigned int hash_string(char *c1) {
    unsigned int hash = 1;
    for (int i = 0; i < c1[i]; i++) {
        hash = ((hash * 7) + c1[i]);
    }
    return (hash%SIZE);
}

void insert_hash_cell (char *c2) {
    unsigned int index = hash_string(c2);
    HASHCELL *new_cell = (HASHCELL *)malloc(sizeof(HASHCELL));
    char *new_mem = (char *) malloc(strlen(c2) + 1);
    new_cell->word = new_mem;
    strcpy(new_mem, c2);
    if (hashtable[index] == 0) {
        hashtable[index] = new_cell;
    }
    else {
        HASHCELL *current_cell = hashtable[index];
        while (1) {
            int compare = strcmp(current_cell->word, new_cell->word);
            if (compare == 0) {
                break;
            }
            else if(current_cell->next == 0){
                current_cell->next = new_cell;
                break;
            }
            current_cell = current_cell->next;
        }
    }
}

void print_hash_table() {
    HASHCELL *current_cell;
    for (int i = 0; i < SIZE; i++){
        printf("%d :", i);
        current_cell = hashtable[i];
        while (current_cell != 0){
            printf("%s ", current_cell->word);
            current_cell = current_cell->next;
        }
        printf("\n");
    }
}

int main () {
    char str[100];

    while (scanf("%s", str) != EOF) {
        insert_hash_cell(str);
    }
    for(int i = 0; i < SIZE; i++) {
        HASHCELL *current_cell = hashtable[i];
        while (current_cell != 0) {
            insert_node(current_cell->word);
            current_cell = current_cell->next;
        }
    }
    print_tree(root);
    
    //print_hash_table();
}