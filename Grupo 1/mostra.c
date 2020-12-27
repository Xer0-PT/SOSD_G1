#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define ARGUMENTS   "\n> Not enough or too much arguments!\n"
#define NO_FILE     "\n> File not found!\n"
#define SUCCESS     "\n\n> Command succeeded!\n"

int main(int argc, char *argv[])
{
	int fd, numberOfCharacters;
	char buffer[200];

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
	
	numberOfCharacters = read(fd, buffer, sizeof(buffer));
	// read não acrescenta o caratere terminal - também resolve o problema de haver lixo binário
	buffer[numberOfCharacters] = '\0';
	
	write(1, "\nFile Content:\n\n", 16);
	write(1, buffer, numberOfCharacters);
	close(fd);

	write(1, SUCCESS, sizeof(SUCCESS));

	return 0;
}