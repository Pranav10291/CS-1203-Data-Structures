//PLaying Around with floating points in for loops
#include<stdio.h>
#include<stdlib.h>

// I want you to change the increment and n and see at what point you end up with an extra loop

int main(int argc, char** argv){

    float i;
    float increment = 0.01;    //Change around this
    float n = 1.0000000001; //And this (this is 10 times increment)
    int count = 0;

    for (i=0.0; i<n; i+=increment) {
        ++count;
        printf("Loop Count: %d\n", count);
    }

    return 0;
}
//Spoiler Alert: Didn't get an extra loop