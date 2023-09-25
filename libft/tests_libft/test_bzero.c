#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello, World!";
    char str2[50] = "Hello, World!";
    
    bzero(str1, 5);
    ft_bzero(str2, 5);
    
    printf("Original: %s, ft_bzero: %s\n", str1, str2);
    
    return 0;
}

