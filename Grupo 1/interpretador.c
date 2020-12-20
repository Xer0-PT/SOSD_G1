#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char command[10];
    int numberOfCharacters;

    while (strcmp(command, "termina\n") != 0)
    {
        //Inicia a insercao com %
        write(1, "% ", 2);
        numberOfCharacters = read(0, command, sizeof(command));

        //write(1, command, numberOfCharacters);

        if(strcmp(command, "mostra\n") == 0)
        {
            write(0, "./mostra", 6);
        }
    }
    
    exit(1);

    // Inicializa a sempre a 1
    static int first_time = 1;

    // Se for a primeira vez, limpa o ecra
    if( first_time )
    {
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
        write(1, CLEAR_SCREEN_ANSI, 12);
        first_time = 0;
    }
    
    return 0;
}
