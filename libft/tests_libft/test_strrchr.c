#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    char *res1 = strrchr(str, 'l');
    char *res2 = ft_strrchr(str, 'l');
    printf("Original: %s, ft_strrchr: %s\n", res1, res2);
    return 0;
}

