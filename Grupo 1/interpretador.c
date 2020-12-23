#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    char commandLine[200];
    char *arguments[200];
    char *token;
    char delimiter[] = " \t\r\n\v\f\0";

    int numberOfCharacters;
    int pid;
    int i;

    while (1)
    {
        // Inicia a insercao com %
        write(1, "% ", 2);

        numberOfCharacters = read(0, commandLine, sizeof(commandLine));
        // read não acrescenta o caratere terminal - também resolve o problema de haver lixo binário
        commandLine[numberOfCharacters] = '\0';

        // Se o comando inserido for "termina" fecha o programa
        if(strcmp(commandLine, "termina") == 0) exit(EXIT_SUCCESS);
        
        if (strlen(commandLine) != 0)
        {           
            // Dividir o input do user para obter um comando e um argumento
            // Função strtok guarda a primeira palavra antes do delimitador
            token = strtok(commandLine, delimiter);

            i = 0;
            while (token != NULL)
            {
                arguments[i] = token;
                token = strtok(NULL, delimiter);
                i++;
            }
            
            pid = fork();

            if(pid == 0) // Processo Filho
            {
                if(execv(arguments[0], arguments) == -1)
                {
                    perror("Error");
                    kill(pid, SIGKILL);
                }
            }
            else if(pid < 0)
            {
                perror("Error");
            }
            else // Processo Pai
            {
                wait(NULL);

                printf("\nCommand '%s' with code '%d' has terminated.\n", arguments[0], pid);
            }
        }            
    }    
    return 0;
}
