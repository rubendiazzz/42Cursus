#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    char c1 = 'A';
    char c2 = '1';
    
    printf("Original: %d, ft_isalnum: %d\n", isalnum(c1), ft_isalnum(c1));
    printf("Original: %d, ft_isalnum: %d\n", isalnum(c2), ft_isalnum(c2));
    
    return 0;
}

