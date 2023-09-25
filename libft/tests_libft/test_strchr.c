#include "libft.h"
#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    char *result = ft_strchr(str, 'W');
    printf("Character found at position: %ld\n", result - str);
    return 0;
}

