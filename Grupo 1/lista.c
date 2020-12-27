#include "library.h"

int main (int argc, char **argv) {

    DIR *dir;
    struct dirent *file;
    char *aux;

    if(argc == 1)
        dir = opendir(".");    
    else if(argc == 2)
        dir = opendir(argv[1]);
    
    if (!dir) 
    {
        perror("opendir()");
        exit(1);
    }

    while ((file = readdir(dir))) 
    {
        if ( !strcmp(file->d_name, ".") || !strcmp(file->d_name, "..") )
        {
                
        } 
        else
        {
            if (file->d_type == 4)
            {
                write(1, "Directory:\n", 12);
            }
            if (file->d_type == 8)
            {
                write(1, "File:\n", 7);
            }
            aux = malloc(sizeof(file->d_name));
            strcpy(aux, file->d_name);
            write(1, aux, sizeof(file->d_name));
            write(1, "\n", 2);
            write(1, "\n", 2);
        }
    }

    if (errno) 
    {
        perror("readdir()");
        exit(1);
    }

    return 0;
}