#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Função para mostrar o número de carateres num ficheiro
int main(int argc, char const *argv[])
{
    int fd, numberOfCharacters;
    char buffer[200], *output;

    if(argc != 2)
    {
        write(2, "Not enough or too much arguments!\n", 34);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
		write(2, "File not found!\n", 16);
        exit(EXIT_FAILURE);
    }

    numberOfCharacters = read(fd, buffer, 200);
    output = malloc(16);

    sprintf(output, "%d\n", numberOfCharacters);

    write(1, output, sizeof(output));
    close(fd);

    write(1, "Command succeeded!\n", 19);

    return 0;
}