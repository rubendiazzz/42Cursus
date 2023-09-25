#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char dest1[50];
    char dest2[50];
    char src[] = "World";
    size_t len1 = strlcpy(dest1, src, sizeof(dest1));
    size_t len2 = ft_strlcpy(dest2, src, sizeof(dest2));
    printf("Original: %lu, ft_strlcpy: %lu\n", len1, len2);
    return 0;
}

