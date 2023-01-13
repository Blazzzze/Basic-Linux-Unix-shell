#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        time_t t1;
        struct tm *clock1;
        char string[80];
        time(&t1);
        clock1 = localtime(&t1);
        strftime(string, 80, "%A %e %B %G %r %Z", clock1);
        printf("%s\n", string);
    }
    else if (argc == 3)
    {
        if (strcmp(argv[2], "-u") == 0)
        {
            time_t t2;
            struct tm *clock2;
            char string[80];
            time(&t2);
            clock2 = gmtime(&t2);
            strftime(string, 80, "%A %e %B %G %r UTC", clock2);
            printf("%s\n", string);
        }
        else if (strcmp(argv[2], "-R") == 0)
        {
            time_t t3;
            struct tm *clock3;
            char string[80];
            time(&t3);
            clock3 = localtime(&t3);
            strftime(string, 80, "%a %e %b %G %r %z", clock3);
            printf("%s\n", string);
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