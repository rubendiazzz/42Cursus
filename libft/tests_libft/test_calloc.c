#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1 = calloc(5, sizeof(int));
    int *arr2 = ft_calloc(5, sizeof(int));
    
    printf("Original: %d, ft_calloc: %d\n", arr1[0], arr2[0]);
    
    free(arr1);
    free(arr2);
    
    return 0;
}

