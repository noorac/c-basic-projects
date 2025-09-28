//list.c 
#include <stdio.h>
#include <stdlib.h>

//headers
#include "list.h"


void print_main_menu() {
    printf("\nChoose one of the options(1,2,3 or 0): ");
    printf("\n\n1. Insert a number of your choise at the end of the list");
    printf("\n2. Insert a number of your choise at the beginning of the list");
    printf("\n3. Print the list");
    printf("\n\n0. Exit(0 or anything other than the other 3)\n");
}

int get_choise() {
    int choise;
    printf("\nInteger: ");
    scanf("%d", &choise);
    return choise;
}

void insert_at_end(struct Node **head, int value) {
    //adds an element at the end
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;

    // if there are no elements in the list, set head to new node
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    //if there ARE elements in the list, find the end and store new_node there
    struct Node *current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insert_at_start(struct Node **head, int value) {
    //adds an element at the beginning
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}
void print_list(struct Node *head) {
    printf("\nPrinting the list: ");
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}
void free_list(struct Node *head) {
    printf("\nFreeing the list .. \n");
    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
}
