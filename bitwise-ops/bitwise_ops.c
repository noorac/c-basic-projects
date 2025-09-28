/*
 * Simulate a simple file permissions system like in unix/linux where each permission is a bit flag
 * Define constants for each permission using #define or const int
 * Create int permissions variable that stores multiple permissions using bitwise OR
 * Function void check_permission(int permissions, int permission_flag) takes current permission state and flag
 *  and prints if granted or denied. In main we assign a set of permissions, and call check_permission for all 4 flags and print the results*/

#include <stdio.h>
#include <stdlib.h>

void check_permission(int permission, int permission_flag, const char *name);

#define P_READ 0x01
#define P_WRITE 0x02
#define P_EXEC 0x04
#define P_DEL 0x08

int main(int argc, char *argv[])
{
    int permission = P_READ | P_EXEC | P_DEL;
    printf("Permission integer: %d\n\n", permission);
    check_permission(permission, P_READ, "Read"); 
    check_permission(permission, P_WRITE, "Write"); 
    check_permission(permission, P_EXEC, "Execute"); 
    check_permission(permission, P_DEL, "Delete"); 
    return EXIT_SUCCESS;
}

void check_permission(int permission, int permission_flag, const char *name) {

    if (permission & permission_flag) {
        printf("%s permission granted, %d\n", name, permission_flag);
    }
    else {
        printf("%s permission denied, %d\n", name, permission_flag);
    }
    return;
}
