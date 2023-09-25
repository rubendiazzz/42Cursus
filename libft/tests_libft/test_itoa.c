#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 42;
    char *result = ft_itoa(num);
    printf("ft_itoa: %s\n", result);
    free(result);
    return 0;
}

