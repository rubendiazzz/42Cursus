#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    printf("Original: %d, ft_memcmp: %d\n", memcmp(str1, str2, 5), ft_memcmp(str1, str2, 5));
    return 0;
}

