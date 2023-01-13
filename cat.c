#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char cur_path[1000];
    getcwd(cur_path, 1000);
    if (argc == 2)
    {
        printf("Enter a valid syntax\n");
    }
    else if (strcmp(argv[2], "-E") == 0 && argc == 4)
    {
        char pp[1000];
        pp[0] = '\0';
        strcat(pp, cur_path);
        strcat(pp, "/");

        char *dirname = argv[3];
        strcat(pp, dirname);
        if (argc != 4)
        {
            printf("\nThe syntax should as be follows");
            printf("\nCommandname file to read\n");
            exit(1);
        }
        int state, count;
        char buffer[2048];
        state = open(dirname, O_RDONLY);
        FILE *file_ptr;
        char c;
        file_ptr = fopen(dirname, "r");
        if (file_ptr == NULL)
        {
            printf("cat: %s: No such file or directory\n", dirname);
            return (0);
        }
        while (1)
        {
            c = fgetc(file_ptr);
            if (c == EOF)
                break;
            else
            {
                if (c == '\n')
                    printf("$");
                printf("%c", c);
            }
        }
        printf("$");
        fclose(file_ptr);
        exit(0);
    }
    else if (strcmp(argv[2], "-E") == 0 && argc == 3)
    {
        printf("Enter a valid syntax\n");
    }
    else if (strcmp(argv[2], "-n") == 0 && argc == 4)
    {
        char pp[1000];
        pp[0] = '\0';
        strcat(pp, cur_path);
        strcat(pp, "/");

        char *dirname = argv[3];
        strcat(pp, dirname);
        if (argc != 4)
        {
            printf("\nThe syntax should as be follows");
            printf("\nCommandname file to read\n");
            exit(1);
        }
        int state;
        state = open(dirname, O_RDONLY);
        // char const *const fileName = "cppbuzz1.txt";
        FILE *file = fopen(dirname, "r");
        if (!file)
        {
            printf("\n Unable to open : %s ", dirname);
            return -1;
        }
        char line[500];
        int lineCount = 1;
        while (fgets(line, sizeof(line), file))
        {
            printf("%d ", lineCount++);
            printf("%s", line);
        }
        fclose(file);
        return 0;
    }
    else if (strcmp(argv[2], "-n") == 0 && argc == 3)
    {
        printf("Enter a valid syntax\n");
    }
    else
    {
        // system("clear");
        for (int i = 2; i < argc; i++)
        {
            char pp[1000];
            // printf("%d", argc);
            pp[0] = '\0';
            strcat(pp, cur_path);
            strcat(pp, "/");
            char *dirname = argv[i];
            strcat(pp, dirname);
            int state, count;
            char buffer[2048];
            state = open(dirname, O_RDONLY);
            FILE *file_ptr;
            char c;
            file_ptr = fopen(dirname, "r");
            if (file_ptr == NULL)
            {
                printf("cat: %s: No such file or directory\n", dirname);
                return (0);
            }
            while (1)
            {
                c = fgetc(file_ptr);
                if (c == EOF)
                    break;
                else
                {
                    printf("%c", c);
                }
            }
            fclose(file_ptr);
            printf("\n");
        }
    }
}