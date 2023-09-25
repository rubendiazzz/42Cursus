#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'a';
    int res1 = toupper(c);
    int res2 = ft_toupper(c);
    printf("Original: %c, ft_toupper: %c\n", res1, res2);
    return 0;
}

