/*
 * Split previous program into 3 files.
 * list.h, declaring the struct Node yype and declare function prototypes
 * list.c implementation file, implementing all linked list functions(insert, print, free, etc)
 * main.c(this file), contains main() and user menu, includes list.h to access the list functionality*/


#include <stdio.h>
#include <stdlib.h>

//headers

#include "list.h"

int main(int argc, char *argv[])
{
    int choise = -1;
    int value;
    struct Node *head = NULL;
    while (choise != 0) {
        print_main_menu();
        choise = get_choise();
        switch (choise) {
            case 1:
                printf("\nInsert at end");
                value = get_choise();
                insert_at_end(&head,value);
                break;
            case 2:
                printf("\nInsert at beginning");
                value = get_choise();
                insert_at_start(&head,value);
                break;
            case 3:
                printf("\nPrint list");
                print_list(head);
                break;
            default:
                choise = 0;
                free_list(head);
                break;
        }
    }
    return EXIT_SUCCESS;
}
