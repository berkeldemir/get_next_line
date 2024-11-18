#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *line;
    fd = open("a.txt", O_RDONLY);
    int a = 20;
    while (a--)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
    }
    return (0);
}