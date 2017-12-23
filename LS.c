#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define SIZE 256

int main (int argc,char** argv)
{
    char file [SIZE];

    if (argc >= 2)
        strcpy(file, argv[1]);
    else
        strcpy(file, ".");

    printf ("\n", file);

    DIR *directory = opendir(file);
    struct dirent *cd = readdir(directory);
    
    while ( (cd = readdir(directory)) != NULL) {
        printf("%d - %s [%d] %d\n",
               cd->d_ino, cd->d_name, cd->d_type, cd->d_reclen);
    }

    closedir (directory);
    return 0;

}
