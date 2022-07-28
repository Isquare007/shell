#include <stdio.h>

#include <dirent.h>

#include <string.h>

  

int main(int ac, char *av[])

{

    struct dirent *de;
    char *file;
    int i;


    DIR *dr = opendir(".");

  

    if (dr == NULL)

    {

        printf("Could not open current directory" );

        return 0;

    }

  

    while ((de = readdir(dr)) != NULL)
    {
	    file = de->d_name;
	    i = strcmp(file, av[1]);
	    if (i == 0)
	    {
		    printf("%s\n", file);
		    break;
	    }
    }
    if (i != 0)
	    printf("not found\n");

    closedir(dr);    

    return 0;

}
