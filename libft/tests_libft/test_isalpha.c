#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    char c1 = 'A';
    
    printf("Original: %d, ft_isalpha: %d\n", isalpha(c1), ft_isalpha(c1));
    
    return 0;
}

