/* #include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> */

#include "library.h"

#define ARGUMENTS   "\n> Not enough or too much arguments!\n"
#define NO_FILE     "\n> File not found!\n"
#define SUCCESS     "\n\n> Command succeeded!\n"

// argv[1] = origem
// argv[2] = destino

int main(int argc, char const *argv[])
{
    int fd1, fd2, numberOfCharacters;
    char buffer[200];

    if(argc != 3)
    {
        write(2, ARGUMENTS, sizeof(ARGUMENTS));
        exit(EXIT_FAILURE);
    }

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDWR | O_APPEND);

    if(fd1 == -1 || fd2 == -1)
    {
        write(2, NO_FILE, sizeof(NO_FILE));
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }

    numberOfCharacters = read(fd1, buffer, sizeof(buffer));
    write(fd2, buffer, numberOfCharacters);

    close(fd1);
    close(fd2);

    write(1, SUCCESS, sizeof(SUCCESS));
    
    return 0;
}
