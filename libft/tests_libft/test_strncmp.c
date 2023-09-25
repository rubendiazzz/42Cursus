#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    int res1 = strncmp(str1, str2, 3);
    int res2 = ft_strncmp(str1, str2, 3);
    printf("Original: %d, ft_strncmp: %d\n", res1, res2);
    return 0;
}

