#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pwd.h>
#include <errno.h>
#include <dirent.h>

#define ARGUMENTS       "\n> Not enough or too much arguments!\n"
#define NO_FILE         "\n> File not found!\n"
#define SUCCESS         "\n\n> Command succeeded!\n"
#define FILE_REMOVED    "\n> File removed!\n"

#endif