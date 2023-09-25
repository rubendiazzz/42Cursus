#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char dest1[50], dest2[50];
    char src[] = "Hello, World!";
    memcpy(dest1, src, strlen(src) + 1);
    ft_memcpy(dest2, src, strlen(src) + 1);
    printf("Original: %s, ft_memcpy: %s\n", dest1, dest2);
    return 0;
}

