#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    char c = ' ';
    printf("Original: %d, ft_isprint: %d\n", isprint(c), ft_isprint(c));
    return 0;
}

