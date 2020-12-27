#include "library.h"

// Função para mostrar o número de carateres num ficheiro
int main(int argc, char const *argv[])
{
    int fd, numberOfCharacters;
    char buffer[200], *output;

    if(argc != 2)
    {
        write(2, ARGUMENTS, sizeof(ARGUMENTS));
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
		write(2, NO_FILE, sizeof(NO_FILE));
        exit(EXIT_FAILURE);
    }

    numberOfCharacters = read(fd, buffer, 200);
    output = malloc(16);

    sprintf(output, "%d\n", numberOfCharacters);

    write(1, "\nNumber of characters: ", 23);
    write(1, output, sizeof(output));
    close(fd);

    write(1, SUCCESS, sizeof(SUCCESS));

    return 0;
}