#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("berk.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("line:%s", line);
        free(line);  // Free the allocated memory after printing the line
    }

    close(fd);  // Close the file descriptor
    return (0);
}