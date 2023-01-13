#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        struct dirent *de;
        char cur_path[1000];
        getcwd(cur_path, 1000);
        DIR *pd = opendir(cur_path);
        struct dirent *cur;
        while (cur = readdir(pd))
        {
            if (cur->d_name[0] != '.')
            {
                puts(cur->d_name);
            }
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[2], "-a") == 0)
        {

            struct dirent *de;
            char cur_path[1000];
            getcwd(cur_path, 1000);
            DIR *dr = opendir(cur_path);

            if (dr == NULL)
            {
                printf("Could not open current directory");
                return 0;
            }
            while ((de = readdir(dr)) != NULL)
                printf("%s\n", de->d_name);

            closedir(dr);
        }
        else if (strcmp(argv[2], "-m") == 0)
        {
            struct dirent *de;
            char cur_path[1000];
            getcwd(cur_path, 1000);
            DIR *pd = opendir(cur_path);
            struct dirent *cur;
            while (cur = readdir(pd))
            {
                if (cur->d_name[0] != '.')
                {
                    printf("%s, \n", cur->d_name);
                }
            }
        }
        else
        {
            printf("Enter a valid syntax and tags\n");
        }
    }
    else
    {
        printf("Enter a valid syntax\n");
    }
    return 0;
}