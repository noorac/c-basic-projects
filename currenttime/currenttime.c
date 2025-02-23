#include <stdio.h>
#include <time.h>

int main () {
    //main function
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    printf("Local time: %s", asctime(local_time));
    return 0;
}
