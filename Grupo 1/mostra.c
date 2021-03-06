#include "library.h"

int main(int argc, char *argv[])
{
	int fd, numberOfCharacters;
	char buffer[BUFFER_SIZE];

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

	if(numberOfCharacters != -1)
	{
		// read não acrescenta o caratere terminal - também resolve o problema de haver lixo binário
		buffer[numberOfCharacters] = '\0';
		
		write(1, "\nFile Content:\n\n", 16);
		write(1, buffer, numberOfCharacters);
		close(fd);

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