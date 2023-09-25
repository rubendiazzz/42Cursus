#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    char *res1 = memchr(str, 'W', strlen(str));
    char *res2 = ft_memchr(str, 'W', strlen(str));
    printf("Original: %c, ft_memchr: %c\n", *res1, *res2);
    return 0;
}

