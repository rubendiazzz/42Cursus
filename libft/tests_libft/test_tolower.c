#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'A';
    int res1 = tolower(c);
    int res2 = ft_tolower(c);
    printf("Original: %c, ft_tolower: %c\n", res1, res2);
    return 0;
}

