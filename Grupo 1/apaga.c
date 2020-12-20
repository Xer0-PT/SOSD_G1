#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int fd;

    if(argc != 2)
    {
        write(2, "Not enough or too much arguments!\n", 34);
        exit(EXIT_FAILURE);
    }
    
    fd = open(argv[1], O_RDONLY);

    if( fd == -1 )
    {
        write(2, "File not found!\n", 16);
        exit(EXIT_FAILURE);
    }

    remove(argv[1]);
    write(1, "File removed!\n", 14);

    return 0;
}
