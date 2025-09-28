/*
 * A program that will ask the user to input a word(single word, no spaces),
 * Then reverses the word, prints the reversed word, and also prints the lenght
 * of the word
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_word(char * word)
{
    printf("Input a word(single word, no spaces): ");
    scanf("%s",word);
}

void reverse_word(char * word, char * reversed_word, int size)
{
    for (int i = 0; i < size; i++)
    {
        reversed_word[i] = word[size-1-i];
    }
}

int main(int argc, char *argv[])
{
    //Variables
    char word[100];
    char reversed_word[100];
    //int size = sizeof(word);
    //int wordlength;


    //get word from user
    get_word(word);
    int size = strlen(word);
    //print Word typed
    printf("\nWord typed: %s",word);
    //reverse the word and print it
    reverse_word(word, reversed_word, size);
    printf("\nWord reversed: %s",reversed_word);
    printf("\nWord length: %d\n", size);


    return EXIT_SUCCESS;
}
