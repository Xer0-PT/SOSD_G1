#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>

#define ARGUMENTS   "  > Not enough or too much arguments!\n"
#define NO_FILE     "  > File not found!\n"
#define SUCCESS     "\n  > Command succeeded!\n"

int main(int argc, char const *argv[])
{
    struct stat file;
    struct passwd *pws;

    char *output;
    long inode;

    if(argc != 2)
    {
        write(2, ARGUMENTS, sizeof(ARGUMENTS));
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &file) == -1)
    {
        write(2, NO_FILE, sizeof(NO_FILE));
        exit(EXIT_FAILURE);
    }

    write(1, "\t> File Type:\t\t", 16);

    switch (file.st_mode & S_IFMT) {
    case S_IFBLK:  write(1, "block device\n", 13);      break;
    case S_IFCHR:  write(1, "character device\n", 17);  break;
    case S_IFDIR:  write(1, "directory\n", 10);         break;
    case S_IFIFO:  write(1, "FIFO/pipe\n", 10);         break;
    case S_IFLNK:  write(1, "symlink\n", 8);            break;
    case S_IFREG:  write(1, "regular file\n", 13);      break;
    case S_IFSOCK: write(1, "socket\n", 7);             break;
    default:       write(1, "unknown?\n", 9);           break;
    }

    inode = file.st_ino;
    output = malloc(8);

    sprintf(output, "%ld\n", inode);

    write(1, "\t> I-node number:\t", 18);
    write(1, output, sizeof(output));

    pws = getpwuid(file.st_uid);

    write(1, "\t> Owner:\t\t\t", 11);
    write(1, pws->pw_name, sizeof(pws->pw_name));

    //printf("\n%s\n", pws->pw_name);

    write(1, SUCCESS, sizeof(SUCCESS));

    return 0;
}
