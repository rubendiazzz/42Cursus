
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Output: %s\n", line);
        free(line);
    }

    if (line == NULL)
        printf("EOF reached or an error occurred\n");

    close(fd);
    return (0);
}
