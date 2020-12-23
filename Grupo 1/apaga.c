#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define ARGUMENTS   "\n> Not enough or too much arguments!\n"
#define NO_FILE     "\n> File not found!\n"

int main(int argc, char const *argv[])
{
    int fd;

    if(argc != 2)
    {
        write(2, ARGUMENTS, sizeof(ARGUMENTS));
        exit(EXIT_FAILURE);
    }
    
    fd = open(argv[1], O_RDONLY);

    if( fd == -1 )
    {
        write(2, NO_FILE, sizeof(NO_FILE));
        exit(EXIT_FAILURE);
    }

    remove(argv[1]);
    write(1, "\n> File removed!\n", 17);

    return 0;
}
