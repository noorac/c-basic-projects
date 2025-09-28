#include <stdio.h>
#include <stdlib.h>

int cio_getint(void);
float cio_getfloat(void);
double cio_getdouble(void);
char cio_getchar(void);
char * cio_getstring(void);


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}

int cio_getint()
//unfinished
{
    char userinput[32];
    size_t idx = 0;
    char c;

    while ((c = getchar()) != '\n' && c != EOF && idx < sizeof(userinput) - 1)
    {
        //if (isdigit(c) || (c == '-' && idx == 0))
        if ((c >= '0' && c <= '9') || (c == '-' && idx == 0))
        {
            userinput[idx++] = c;
        }
    }
    userinput[idx] = '\0';
    return atoi(userinput);
}

float cio_getfloat()
//unfinished
{
    char userinput[32];
    size_t idx = 0;
    char c;

    while ((c = getchar()) != '\n' && c != EOF && idx < sizeof(userinput) - 1)
    {
        //if (isdigit(c) || (c == '-' && idx == 0))
        if ((c >= '0' && c <= '9') || (c == '-' && idx == 0))
        {
            userinput[idx++] = c;
        }
    }
    userinput[idx] = '\0';
    return atof(userinput);
}

double cio_getdouble()
//unfinished
{
    char userinput[32];
    size_t idx = 0;
    char c;

    while ((c = getchar()) != '\n' && c != EOF && idx < sizeof(userinput) - 1)
    {
        //if (isdigit(c) || (c == '-' && idx == 0))
        if ((c >= '0' && c <= '9') || (c == '-' && idx == 0))
        {
            userinput[idx++] = c;
        }
    }
    userinput[idx] = '\0';
    return atol(userinput);
}

char cio_getchar()
{
    //Returns a single character, if more is inputted
    //it will be discarded. If simply press enter '\0'
    //is returned

    char userinput = '\0';
    int gotfirstchar = 0;
    char c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (gotfirstchar == 0) {
            userinput = c;
            gotfirstchar = 1;
        }
    }
    return userinput;
}

char * cio_getstring()
{
    //Returns a string. String length updates as the user
    //types in values. 
    char * userinput = NULL;
    size_t size = 0;
    size_t cap = 0;

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if ( size + 1 >= cap) {
            //ensure capacity for new character and nullterminator
            cap = (cap == 0) ? 16: cap * 2;
            char * temp = realloc(userinput, cap);
            if (temp == NULL) {
                free(userinput);
                fprintf(stderr, "Realloc failed .. \n");
                return NULL;
            }
            userinput = temp;
        }
        userinput[size++] = (char)c;
    }
    if (userinput) {
        //null-termination
        userinput[size] = '\0';
    } else {
        //return empty string if user simply presses enter immediately.
        userinput = malloc(1);
        if (userinput) userinput[0] = '\0';
    }
    return userinput;
}
