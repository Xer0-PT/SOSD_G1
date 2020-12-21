#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char tempCommandLine[200];
    char *commandLine;
    char command[30];
    char file[30];
    char *delimiter = " ";

    int numberOfCharacters;

    while (strcmp(tempCommandLine, "termina\n") != 0)
    {
        // Inicia a insercao com %
        write(1, "% ", 2);

        numberOfCharacters = read(0, tempCommandLine, 200);

        // Se o comando inserido for "termina" fecha o programa
        if(strcmp(tempCommandLine, "termina\n") == 0) exit(1);

        strcpy(command, strtok(tempCommandLine, delimiter));
        //strcpy(file, strtok(NULL, delimiter));

        printf("%s\n", command);
        //printf("%s\n", file);


        /* commandLine = malloc(numberOfCharacters * sizeof(char) + 1); */
/*        commandLine = malloc(numberOfCharacters);
        strcpy(commandLine, tempCommandLine);


        write(1, commandLine, sizeof(commandLine));
 */
/*         
        // Token aponta para a primeira palavra
        strcpy(command, strtok(tempCommandLine, delimiter));

        // Token aponta para a segunda palavra
        strcpy(file, strtok(NULL, delimiter));

        write(1, command, sizeof(command));
        write(1, file, sizeof(file));
 */
    }
    
    return 0;
}
