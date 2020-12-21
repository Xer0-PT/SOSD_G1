#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// Função para mostrar conteúdo do ficheiro
int main(int argc, char *argv[])
{
	int fd, numberOfCharacters;
	char buffer[200];

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
	
	numberOfCharacters = read(fd, buffer, sizeof(buffer));
	// read não acrescenta o caratere terminal
	buffer[numberOfCharacters - 1] = '\0';
	
	write(1, buffer, numberOfCharacters);
	close(fd);

	write(1, "Command succeeded!\n", 19);

	return 0;
}