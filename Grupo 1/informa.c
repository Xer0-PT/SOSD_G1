#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct stat file;

    if(argc != 2)
    {
        write(2, "Not enough or too much arguments!\n", 34);
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
