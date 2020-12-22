#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    char commandLine[200];
    char *command;
    char *argument;
    char *token;
    char *newargv[] = {NULL};
    char delimiter[] = " \t\r\n\v\f\0";

    int numberOfCharacters;
    int pid;

    while (1)
    {
        // Inicia a insercao com %
        write(1, "% ", 2);

        numberOfCharacters = read(0, commandLine, sizeof(commandLine));
        // read não acrescenta o caratere terminal - também resolve o problema de haver lixo binário
        commandLine[numberOfCharacters - 1] = '\0';

        // Se o comando inserido for "termina" fecha o programa
        if(strcmp(commandLine, "termina") == 0) exit(EXIT_SUCCESS);
        
        if (commandLine != NULL)
        {
            //!!! Vai ser preciso alterar isto para colocar os argumentos em array
            //!!! Porque há comandos que não precisam de argumentos
            //!!! E há um comando que precisa de 3 argumentos
            


            // Dividir o input do user para obter um comando e um argumento
            // Função strtok guarda a primeira palavra antes do delimitador
            token = strtok(commandLine, delimiter);
            // Alocamos memória para poder guardar essa palavra na variável command
            command = malloc(sizeof(token));
            strcpy(command, token);

            token = strtok(NULL, delimiter);
            argument = malloc(sizeof(token));
            strcpy(argument, token);

            pid = fork();

            if(pid == 0) // Processo Filho
            {
                puts("Filho iniciou!");
                if(execl(command, command, argument, NULL) == -1)
                    perror("Command");
            }
            else // Processo Pai
            {
                wait(NULL);

                printf("\nTerminou comando '%s' com codigo '%d'.", command, pid);

                free(command);
                free(argument);
            }
        }            
    }    
    return 0;
}
