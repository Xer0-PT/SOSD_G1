#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char commandLine[200];
    char *command;
    char *argument;
    char *token;
    char *newargv[] = {NULL};



    int numberOfCharacters;

    while (1)
    {
        // Inicia a insercao com %
        write(1, "% ", 2);

        numberOfCharacters = read(0, commandLine, sizeof(commandLine));
        // read não acrescenta o caratere terminal - também resolve o problema de haver lixo binário
        commandLine[numberOfCharacters - 1] = '\0';

        // Se o comando inserido for "termina" fecha o programa
        if(strcmp(commandLine, "termina") == 0) exit(EXIT_SUCCESS);

        // Dividir o input do user para obter um comando e um argumento
        // Função strtok guarda a primeira palavra antes do delimitador
        token = strtok(commandLine, " ");
        // Alocamos memória para poder guardar essa palavra na variável command
        command = malloc(sizeof(token));
        strcpy(command, token);

        token = strtok(NULL, "\0");
        argument = malloc(sizeof(token));
        strcpy(argument, token);
    
//        printf("%s\n\n%s\n\n", command, argument);


        // A partir daqui começam os forks e cenas
        
        /* ------------------
         Isto está mal
         ------------------ */

        newargv[0] = command;
        newargv[1] = argument;

        fork();
        execv(newargv[0], newargv[1]);

    }
    
    return 0;
}
