#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    size_t len1 = strlen(str);
    size_t len2 = ft_strlen(str);
    printf("Original: %lu, ft_strlen: %lu\n", len1, len2);
    return 0;
}

