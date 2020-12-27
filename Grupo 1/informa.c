#include "library.h"

int main(int argc, char const *argv[])
{
    struct stat file;
    struct passwd *pws;

    char *output;
    char *owner;
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

    write(1, "\n> File Type:\t\t", 16);

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

    write(1, "> I-node number:\t", 17);
    write(1, output, sizeof(output));

    pws = getpwuid(file.st_uid);

    write(1, "> Owner:\t\t\t", 10);
    owner = malloc(sizeof(pws->pw_name));
    strcpy(owner, pws->pw_name);
    write(1, owner, sizeof(owner));

    write(1, SUCCESS, sizeof(SUCCESS));

    return 0;
}
