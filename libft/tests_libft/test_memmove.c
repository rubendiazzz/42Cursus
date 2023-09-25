#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "abcdef";
    char str2[] = "abcdef";
    memmove(str1 + 1, str1, 5);
    ft_memmove(str2 + 1, str2, 5);
    printf("Original: %s, ft_memmove: %s\n", str1, str2);
    return 0;
}

