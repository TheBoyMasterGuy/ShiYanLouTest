#include <iostream>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

/* swap function, swap a and b */
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int getrand(int min, int max)
{
    return (min+rand()%(max-min+1));
}
