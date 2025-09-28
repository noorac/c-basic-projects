/*helper.c*/

//added extern in helper.h, this made it a read-only error in compilation instead of undecleared when trying to 
//call static int
//now static is removed
int counter = 0;
int increment_counter() {
    return ++counter;
}
