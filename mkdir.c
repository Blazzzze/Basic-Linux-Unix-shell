#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
char *dirname;
int main(int argc, char *argv[])
{
    if (argc == 3)
    {

        int check;
        // char cur_path[1000];
        // getcwd(cur_path,1000);
        char pp[1000];
        char cur_path[1000];
        getcwd(cur_path, 1000);
        pp[0] = '\0';
        strcat(pp, cur_path);
        strcat(pp, "/");

        dirname = argv[2];
        strcat(pp, dirname);
        // strcat(dirname,cur_path);
        check = mkdir(dirname, S_IRWXU | S_IRWXG | S_IRWXO);
        if (check)
        {
            printf("Unable to create directory\n");
            exit(1);
        }
    }
    else if (argc == 4)
    {
        if (strcmp(argv[2], "-v") == 0)
        {
            int check;
            // char cur_path[1000];
            // getcwd(cur_path,1000);
            char pp[1000];
            char cur_path[1000];
            getcwd(cur_path, 1000);
            pp[0] = '\0';
            strcat(pp, cur_path);
            strcat(pp, "/");

            dirname = argv[3];
            strcat(pp, dirname);
            // strcat(dirname,cur_path);
            check = mkdir(dirname, S_IRWXU | S_IRWXG | S_IRWXO);
            if (!check)
                printf("mkdir: created directory %s\n", dirname);
            else
            {
                printf("Unable to create directory\n");
                exit(1);
            }
        }
        if (strcmp(argv[2], "-p") == 0)
        {
            int check;
            // // char cur_path[1000];
            // // getcwd(cur_path,1000);
            // char pp[1000];
            // char cur_path[1000];
            // getcwd(cur_path, 1000);
            // pp[0] = '\0';
            // strcat(pp, cur_path);
            // strcat(pp, "/");

            // char *dirname = argv[3];
            // strcat(pp, dirname);
            // strcat(dirname,cur_path);
            // check = mkdir(dirname, S_IRWXU | S_IRWXG | S_IRWXO);
            char pp[1000];
            char cur_path[1000];
            getcwd(cur_path, 1000);
            pp[0] = '\0';
            strcat(pp, cur_path);
            strcat(pp, "/");

            dirname = argv[3];
            strcat(pp, dirname);
            // strcat(dirname,cur_path);
            check = mkdir(dirname, S_IRWXU | S_IRWXG | S_IRWXO);
            // if (!check)
            //     printf("mkdir: created directory %s\n", dirname);
            // else
            // {
            //     printf("Unable to create directory\n");
            //     exit(1);
            // }
        }
        else
        {
            printf("Please enter correct syntax and tags\n");
        }
    }
    else
    {
        printf("Please enter correct syntax and tags\n");
    }

    return 0;
}