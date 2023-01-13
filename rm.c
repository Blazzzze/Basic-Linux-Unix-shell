#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        printf("Enter a valid syntax\n");
    }
    else if (argc == 3)
    {
        int state = remove(argv[2]);
        if (!state)
        {
            printf("Removed %s\n", argv[2]);
            remove(argv[2]);
        }
        else
        {
            printf("Error in deleteing: %s\n", strerror(errno));
            return 0;
        }
    }
    else if (argc == 4)
    {
        if (strcmp(argv[2], "-d") == 0)
        {
            while (1)
            {
                // printf("Are you sure you want to delete
                int state = rmdir(argv[3]);
                if (!state)
                {
                    printf("Removed %s\n", argv[3]);
                    return 0;
                }
                else
                {
                    printf("Error in deleteing: %s\n", strerror(errno));
                    return 0;
                }
            }
        }
        else if (strcmp(argv[2], "-v") == 0)
        {
            int state = remove(argv[3]);
            if (!state)
            {
                printf("Removed the file %s\n", argv[3]);
                return 0;
            }
            else
            {
                printf("Error in deleteing: %s\n", strerror(errno));
                return 0;
            }
        }
        else
        {
            printf("Enter a valid syntax and tags\n");
        }
    }

    return 0;
}