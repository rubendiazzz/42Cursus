#include "libft.h"
#include <stdio.h>

char to_uppercase(unsigned int i, char c) {
    return toupper(c);
}

int main() {
    char str[] = "hello";
    char *result = ft_strmapi(str, to_uppercase);
    printf("Transformed string: %s\n", result);
    return 0;
}

