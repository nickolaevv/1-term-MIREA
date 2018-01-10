#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define SIZE 256

int main (unsigned long argc,char** argv)
{
    char file [SIZE];

    if (argc >= 2)
        strcpy(file, argv[1]);
    else
        strcpy(file, ".");

    printf ("\n");

    DIR *directory = opendir(file);
    struct dirent *cd = readdir(directory);
    
    while ( (cd = readdir(directory)) != NULL) {
        printf("%u- %s [%u] %d\n",
               (int)cd->d_ino, cd->d_name, cd->d_type, cd->d_reclen);
    }

    closedir (directory);
        return 0;

}
