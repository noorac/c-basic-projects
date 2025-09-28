/*
 * program will be able to:
 * add new contacts, list all contacts, save contacts to a file,
 * load contacts from a file, exit(and free memory).
 * build using struct Contact 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[100];
    char phone[20];
};

void load_contacts(const char *filename, struct Contact **contacts, int *size, int *capacity);
void save_contacts(const char *filename, struct Contact *contacts, int size);
void list_contacts(struct Contact *contacts, int size);
struct Contact add_contacts();

int main(int argc, char *argv[])
{
    #define FILENAME "address_book.txt"
    int capacity = 2;
    int size = 0;
    struct Contact *contacts = malloc(capacity * sizeof(struct Contact));

    if (contacts == NULL) {
        perror("\n\nMalloc failed, exiting..");
        return 1;
    }


    while (1) {
        int choise = -1;
        printf("Menu:\n");
        printf("1: Add contact\n");
        printf("2: List contact\n");
        printf("3: Save contact\n");
        printf("4: Load contact\n\n");
        printf("0: Exit\n\n");

        printf("Enter menu choise: ");
        while (scanf("%d", &choise) == 0) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("\nInvalid choise, try again: ");

        }

        switch (choise) {
            case 1:
                contacts[size++] = add_contacts();
                break;
            case 2:
                list_contacts(contacts, size);
                break;
            case 3:
                save_contacts(FILENAME, contacts, size);
                break;
            case 4:
                load_contacts(FILENAME, &contacts, &size, &capacity);
                break;
            case 0:
                return EXIT_SUCCESS;
        }
        //resize
        if (size == capacity) {
            capacity *= 2;
            struct Contact *temp= realloc(contacts,capacity * sizeof(struct Contact));
            if (contacts == NULL) {
                perror("Realloc failed");
                return EXIT_FAILURE;
            }
            else {
                contacts = temp;
                //free(temp);
            }
        }
    }
    free(contacts);


    //exit
    return EXIT_SUCCESS;
}

void load_contacts(const char *filename, struct Contact **contacts, int *size, int *capacity) {
    printf("Loading contacts\n");
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open for reading");
        return;
    }

    char line[128];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        if (*size >= *capacity) {
            *capacity *= 2;
            struct Contact *temp = realloc(*contacts, *capacity * sizeof(struct Contact));
            if (!temp) {
                perror("Failed to reallocate memory");
                fclose(file);
                free(*contacts);
                return;
            }
            *contacts = temp;
        }
        char *comma = strchr(line, ',');
        if (!comma) continue;

        *comma = '\0';
        strncpy((*contacts)[*size].name, line, sizeof((*contacts)[*size].name));
        strncpy((*contacts)[*size].phone, comma + 1, sizeof((*contacts)[*size].phone));

        (*contacts)[*size].name[sizeof((*contacts)[*size].name) -1 ]  = '\0';
        (*contacts)[*size].phone[sizeof((*contacts)[*size].phone) -1] = '\0';
        (*size)++;
    }
}
void save_contacts(const char *filename, struct Contact *contacts, int size) {
    printf("Saving contacts\n");
    
    FILE *file = fopen(filename, "w");
    if(!file) {
        perror("Failed to open file");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s,%s\n", contacts[i].name,contacts[i].phone);
    }
    fclose(file);
}
void list_contacts(struct Contact *contacts, int size) {
    printf("Listing contacts\n");
    for (int i = 0; i < size; i++) {
        printf("Entry %d - Name: %s - Phone number: %s", i, contacts[i].name, contacts[i].phone);
    }
}
struct Contact add_contacts() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    printf("\nAdding a contact");
    struct Contact c;

    printf("\nEnter full name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    printf("\nEnter phone number: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    return c;
}
