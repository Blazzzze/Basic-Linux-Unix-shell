#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#ifdef __unix__
#define IS_POSIX 1
#else
#define IS_POSIX 0
#endif
// void *ls(void *arg)
// {
//     char pp[1000];
//     char cur_path[1000];
//     getcwd(cur_path, 1000);
//     pp[0] = '\0';
//     strcat(pp, cur_path);
//     strcat(pp, "/");
//     strcat(pp, "./ls");
//     pid_t pid;
//     // pid = pthread();
//     int status;
//     if (pid < 0)
//     {
//         fprintf(stderr, "Pthread Failed");
//         return NULL;
//     }
//     else if (pid == 0)
//         system(pp);
//     else
//         waitpid(pid, &status, 0);
// }
// void *cat(void *arg)
// {
//     char pp[1000];
//     char cur_path[1000];
//     getcwd(cur_path, 1000);
//     pp[0] = '\0';
//     strcat(pp, cur_path);
//     strcat(pp, "/");
//     strcat(pp, "./cat");
//     pid_t pid;
//     // pid = pthread();
//     int status;
//     if (pid < 0)
//     {
//         fprintf(stderr, "Pthread Failed");
//         return NULL;
//     }
//     else if (pid == 0)
//         system(pp);
//     else
//         waitpid(pid, &status, 0);
// }
// void *date(void *arg)
// {
//     char pp[1000];
//     char cur_path[1000];
//     getcwd(cur_path, 1000);
//     pp[0] = '\0';
//     strcat(pp, cur_path);
//     strcat(pp, "/");
//     strcat(pp, "./date");
//     pid_t pid;
//     // pid = pthread();
//     int status;
//     if (pid < 0)
//     {
//         fprintf(stderr, "Pthread Failed");
//         return NULL;
//     }
//     else if (pid == 0)
//         system(pp);
//     else
//         waitpid(pid, &status, 0);
// }
// void *rm(void *arg)
// {
//     char pp[1000];
//     char cur_path[1000];
//     getcwd(cur_path, 1000);
//     pp[0] = '\0';
//     strcat(pp, cur_path);
//     strcat(pp, "/");
//     strcat(pp, "./rm");
//     pid_t pid;
//     // pid = pthread();
//     int status;
//     if (pid < 0)
//     {
//         fprintf(stderr, "Pthread Failed");
//         return NULL;
//     }
//     else if (pid == 0)
//         system(pp);
//     else
//         waitpid(pid, &status, 0);
// }
// void *mkdir(void *arg)
// {
//     char pp[1000];
//     char cur_path[1000];
//     getcwd(cur_path, 1000);
//     pp[0] = '\0';
//     strcat(pp, cur_path);
//     strcat(pp, "/");
//     strcat(pp, "./mkdir");
//     pid_t pid;
//     // pid = pthread();
//     int status;
//     if (pid < 0)
//     {
//         fprintf(stderr, "Pthread Failed");
//         return NULL;
//     }
//     else if (pid == 0)
//         system(pp);
//     else
//         waitpid(pid, &status, 0);
// }
int main(int argc, char *argv[])
{
    if (strcmp(argv[argc - 1], "&t\n") != 0)
    {

        if (strcmp(argv[1], "cd") == 0)
        {

            if (argv[2] == NULL)
            {
                fprintf(stderr, "sh: expected argument to \"cd\"\n");
            }
            else
            {
                if (argc == 3)
                {
                    int flag = chdir(argv[2]);
                    if (flag == 0)
                    {
                        // perror("sh");
                        printf("You are in the folder");
                        char cwd[1024];
                        getcwd(cwd, sizeof(cwd));
                        printf(" %s\n", cwd);
                    }
                    else
                    {
                        perror("sh");
                        char cwd[1024];
                        getcwd(cwd, sizeof(cwd));
                        printf(" %s\n", cwd);
                    }
                }
                else if (strcmp(argv[2], "..") == 0)
                {
                    // char cwd[1024];
                    int status = chdir("..");
                    if (status == -1)
                        perror("cd");
                }
                else if (strcmp(argv[2], "~") == 0)
                {
                    char *SHELL_PATH;
                    char cwd[1024];
                    strcpy(cwd, SHELL_PATH);
                    strcat(cwd, argv[2] + 1);
                    int status = chdir(cwd);
                    if (status == -1)
                        perror("cd ");
                }
            }
            return 1;
        }
        else if (strcmp(argv[1], "echo") == 0)
        {
            // int c = 0;
            // int cr;
            //    printf("\n Enter input: ");
            // c = fgets(argv[]);
            // cr = fgets(argv[]);
            // putchar(c);
            if (argc == 2)
            {
                printf("Please enter the string you want to echo\n");
            }
            else if (argc == 3)
            {
                int n = strlen(argv[2]);
                if (n != 0)
                {
                    printf("%s\n", argv[2]);
                }
                else
                {
                    printf("Please enter the string you want to echo\n");
                }
            }
            else if (strcmp(argv[2], "-n") == 0 && argc == 4)
            {
                int n = strlen(argv[3]);
                if (n != 0)
                {
                    printf("%s", argv[3]);
                }
                else
                {
                    printf("Please enter the string you want to echo\n");
                }
            }
            else if (strcmp(argv[2], "-E") == 0 && argc == 4)
            {
                int n = strlen(argv[3]);
                if (n != 0)
                {
                    printf("%s\n", argv[3]);
                }
                else
                {
                    printf("Please enter the string you want to echo\n");
                }
            }
            else
            {
                printf("Enter valid syntax\n");
            }
        }
        else if (strcmp(argv[1], "pwd") == 0)
        {
            if (argc == 2)
            {
                char cwd[1024];
                getcwd(cwd, sizeof(cwd));
                printf("Current working directory: %s\n", cwd);
            }
            else if (strcmp(argv[2], "-L") == 0)
            {
                char cwd[1024];
                getcwd(cwd, sizeof(cwd));
                printf("Current working directory: %s\n", cwd);
            }
            else if (strcmp(argv[2], "-P") == 0)
            {
                char cwd[1024];
                getcwd(cwd, sizeof(cwd));
                printf("Current working directory: %s\n", cwd);
            }
            else
            {
                printf("Enter valid syntax\n");
            }
        }
        else if (strcmp(argv[1], "ls") == 0)
        {
            char pp[1000];
            char cur_path[1000];
            getcwd(cur_path, 1000);
            pp[0] = '\0';
            strcat(pp, cur_path);
            strcat(pp, "/");
            strcat(pp, "./ls");
            pid_t pid;
            pid = fork();
            int status;
            if (pid < 0)
            {
                fprintf(stderr, "Fork Failed");
                return 1;
            }
            else if (pid == 0)
                execvp(pp, argv);
            else
                waitpid(pid, &status, 0);
        }
        else if (strcmp(argv[1], "cat") == 0)
        {
            char pp[1000];
            char cur_path[1000];
            getcwd(cur_path, 1000);
            pp[0] = '\0';
            strcat(pp, cur_path);
            strcat(pp, "/");
            strcat(pp, "./cat");
            pid_t pid;
            pid = fork();
            int status;
            if (pid < 0)
            {
                fprintf(stderr, "Fork Failed");
                return 1;
            }
            else if (pid == 0)
                execvp(pp, argv);
            else
                waitpid(pid, &status, 0);
        }
        else if (strcmp(argv[1], "date") == 0)
        {
            char pp[1000];
            char cur_path[1000];
            getcwd(cur_path, 1000);
            pp[0] = '\0';
            strcat(pp, cur_path);
            strcat(pp, "/");
            strcat(pp, "./date");
            pid_t pid;
            pid = fork();
            int status;
            if (pid < 0)
            {
                fprintf(stderr, "Fork Failed");
                return 1;
            }
            else if (pid == 0)
            {
                execvp(pp, argv);
            }
            else
                waitpid(pid, &status, 0);
        }
        else if (strcmp(argv[1], "rm") == 0)
        {
            char pp[1000];
            char cur_path[1000];
            getcwd(cur_path, 1000);
            pp[0] = '\0';
            strcat(pp, cur_path);
            strcat(pp, "/");
            strcat(pp, "./rm");
            pid_t pid;
            pid = fork();
            int status;
            if (pid < 0)
            {
                fprintf(stderr, "Fork Failed");
                return 1;
            }
            else if (pid == 0)
                execvp(pp, argv);
            else
                waitpid(pid, &status, 0);
        }
        else if (strcmp(argv[1], "mkdir") == 0)
        {
            char pp[1000];
            char cur_path[1000];
            getcwd(cur_path, 1000);
            pp[0] = '\0';
            strcat(pp, cur_path);
            strcat(pp, "/");
            strcat(pp, "./mkdir");
            pid_t pid;
            pid = fork();
            int status;
            if (pid < 0)
            {
                fprintf(stderr, "Fork Failed");
                return 1;
            }
            else if (pid == 0)
                execvp(pp, argv);
            else
                waitpid(pid, &status, 0);
        }
    }
    else
    {
        // if (strcmp(argv[1], "ls"))
        // {
        //     char arg[1000];
        //     memcpy(arg, argv, 1000);
        //     arg[1000] = '\0';
        //     pthread_t t1;
        //     pthread_create(&t1, NULL, ls, (void *)arg);
        //     pthread_join(t1, NULL);
        // }
        // else if (strcmp(argv[1], "cat"))
        // {
        //     char arg[1000];
        //     memcpy(arg, argv, 1000);
        //     arg[1000] = '\0';
        //     pthread_t t1;
        //     pthread_create(&t1, NULL, cat, (void *)arg);
        //     pthread_join(t1, NULL);
        // }
        // else if (strcmp(argv[1], "date"))
        // {
        //     char arg[1000];
        //     memcpy(arg, argv, 1000);
        //     arg[1000] = '\0';
        //     pthread_t t1;
        //     pthread_create(&t1, NULL, date, (void *)arg);
        //     pthread_join(t1, NULL);
        // }
        // else if (strcmp(argv[1], "rm"))
        // {
        //     char arg[1000];
        //     memcpy(arg, argv, 1000);
        //     arg[1000] = '\0';
        //     pthread_t t1;
        //     pthread_create(&t1, NULL, rm, (void *)arg);
        //     pthread_join(t1, NULL);
        // }
        // else if (strcmp(argv[1], "mkdir"))
        // {
        //     char arg[1000];
        //     memcpy(arg, argv, 1000);
        //     arg[1000] = '\0';
        //     pthread_t t1;
        //     pthread_create(&t1, NULL, mkdir, (void *)arg);
        //     pthread_join(t1, NULL);
        // }
    }
    return 0;
}