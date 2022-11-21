#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

int main(int argc, char **argv){
    int person[2][2] = {{1,2},{3,4}};
    int location[2][2] = {{0,0},{0,0}};

    printf("Array before the syscall\n");
    int i = 0;
    int j = 0;

    printf("%d %d\n", location[0][0], location[0][1]);
    printf("%d %d\n", location[1][0], location[1][1]);

    long result = syscall(451, *person, *location, 2, 2);
    perror("h");
    printf("Array after the syscall\n");

    i = 0;
    j = 0;

    printf("%d %d\n", location[0][0], location[0][1]);
    printf("%d %d\n", location[1][0], location[1][1]);
    printf("System call returned. %ld\n", result);
    return result;
}