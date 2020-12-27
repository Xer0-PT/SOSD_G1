#include "library.h"

#define NR_OF_COMMANDS 6
#define MAX_STRING_SIZE 11

int main(int argc, char const *argv[])
{
    char commandLine[200];
    char *arguments[200];
    char *token;
    char delimiter[] = " \t\n";

    char listOfCommands[NR_OF_COMMANDS][MAX_STRING_SIZE] = {"acrescenta", "apaga", "conta", "informa", "lista", "mostra"};
    int commandAccepted = -1;

    int numberOfCharacters;
    int pid;
    int i;

    while (1)
    {
        write(1, "% ", 2);

        numberOfCharacters = read(0, commandLine, sizeof(commandLine));

        // read não acrescenta o caratere terminal - também resolve o problema de haver lixo binário
        commandLine[numberOfCharacters] = '\0';

        if(strcmp(commandLine, "\n") == 0)
        {}
        else
        {     
            i = 0;
            commandAccepted = -1;   

            if(strcmp(commandLine, "termina\n") == 0) exit(EXIT_SUCCESS);

            // Função strtok guarda a primeira palavra antes do delimitador
            token = strtok(commandLine, delimiter);

            while (token != NULL)
            {
                arguments[i] = token;
                token = strtok(NULL, delimiter);
                i++;
            }

            // Colocar o seguinte argumento a NULL para utilizar em comandos
            // que não precisem de mais argumentos - Por exemplo 'lista'
            arguments[i] = NULL;

            // Verificar se o comando inserido faz parte da lista de comandos
            for (int j = 0; j < NR_OF_COMMANDS; j++)
            {
                if(strcmp(arguments[0], listOfCommands[j]) == 0)
                    commandAccepted = 1;
            }     
            
            if (commandAccepted != 1)
                write(2, "Unknown command!\n", 17);
            else
            {            
                pid = fork();

                if(pid < 0)
                    perror("fork()");
                else if(pid == 0) // Processo Filho
                {
                    if(execv(arguments[0], arguments) == -1)
                        perror("execv()");
                }
                else // Processo Pai
                {
                    wait(NULL);

                    printf("\nCommand '%s' with code '%d' has terminated.\n", arguments[0], pid);
                }
            }        
        }
    }    
    return 0;
}
