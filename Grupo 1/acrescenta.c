#include "library.h"

// argv[1] = origem
// argv[2] = destino

int main(int argc, char const *argv[])
{
    int fd1, fd2, numberOfCharacters;
    char buffer[BUFFER_SIZE];

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

    if(numberOfCharacters != -1)
    {
        write(fd2, buffer, numberOfCharacters);

        close(fd1);
        close(fd2);

        write(1, SUCCESS, sizeof(SUCCESS));
        exit(EXIT_SUCCESS);
    }
    else
    {
        perror("read()");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
