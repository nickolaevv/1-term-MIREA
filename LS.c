#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define SIZE 256

int main (int argc,char** argv)
{
    char file [SIZE];
    DIR *directory = opendir(file);
    struct dirent *cd = readdir(directory);

    if (argc > 2)
        strcpy(file, argv[1]);
    else
        strcpy(file, ".");

    printf ("\n", file);

    while (cd != NULL)
        printf ("%s\n", cd -> d_name );

    closedir (directory);
    return 0;

}
