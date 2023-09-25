#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello, World!";
    char str2[50] = "Hello, World!";
    memset(str1, '$', 5);
    ft_memset(str2, '$', 5);
    printf("Original: %s, ft_memset: %s\n", str1, str2);
    return 0;
}

