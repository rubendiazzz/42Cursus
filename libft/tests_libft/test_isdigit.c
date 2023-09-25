#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    char c = '5';
    printf("Original: %d, ft_isdigit: %d\n", isdigit(c), ft_isdigit(c));
    return 0;
}

