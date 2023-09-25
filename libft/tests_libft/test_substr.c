#include "libft.h"
#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    char *result = ft_substr(str, 7, 5);
    printf("Substring: %s\n", result);
    return 0;
}

