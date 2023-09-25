#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char haystack[] = "Hello, World!";
    char needle[] = "World";
    char *res1 = strnstr(haystack, needle, 12);
    char *res2 = ft_strnstr(haystack, needle, 12);
    printf("Original: %s, ft_strnstr: %s\n", res1, res2);
    return 0;
}

