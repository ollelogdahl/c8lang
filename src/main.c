#include <stdio.h>

#include "c8c.h"

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("no file to compile.\n");
        return 1;
    }
    
    c8c_compile(argv[1]);

    return 0;
}