#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char dest1[50] = "Hello";
    char dest2[50] = "Hello";
    char src[] = "World";
    size_t len1 = strlcat(dest1, src, sizeof(dest1));
    size_t len2 = ft_strlcat(dest2, src, sizeof(dest2));
    printf("Original: %lu, ft_strlcat: %lu\n", len1, len2);
    return 0;
}

