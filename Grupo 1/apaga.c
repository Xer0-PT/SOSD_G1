#include "library.h"

int main(int argc, char const *argv[])
{
    int fd;

    if(argc != 2)
    {
        write(2, ARGUMENTS, sizeof(ARGUMENTS));
        exit(EXIT_FAILURE);
    }
    
    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        write(2, NO_FILE, sizeof(NO_FILE));
        exit(EXIT_FAILURE);
    }

    close(fd);
    
    if(remove(argv[1]) == 0)
        write(1, FILE_REMOVED, sizeof(FILE_REMOVED));
    else
    {
        perror("remove()");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
