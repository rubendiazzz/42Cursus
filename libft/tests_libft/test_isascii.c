#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'A';
    printf("Original: %d, ft_isascii: %d\n", isascii(c), ft_isascii(c));
    return 0;
}

