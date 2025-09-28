//list.h 

#ifndef LIST_H
#define LIST_H

// Struct node definition


struct Node {
    int value;
    struct Node *next;
};

//function prototypes


void insert_at_end(struct Node **head, int value);
void insert_at_start(struct Node **head, int value);
void print_list(struct Node *head);
void free_list(struct Node *head);
void print_main_menu();
int get_choise();

#endif // LIST_H
