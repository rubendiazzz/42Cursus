#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str1[] = "42";
    char str2[] = "-42";
    char str3[] = "  42";
    
    printf("Original: %d, ft_atoi: %d\n", atoi(str1), ft_atoi(str1));
    printf("Original: %d, ft_atoi: %d\n", atoi(str2), ft_atoi(str2));
    printf("Original: %d, ft_atoi: %d\n", atoi(str3), ft_atoi(str3));
    
    return 0;
}

