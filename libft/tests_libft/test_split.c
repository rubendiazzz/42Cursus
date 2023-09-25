#include "libft.h"
#include <stdio.h>

int main() {
    char **result = ft_split("Hello World", ' ');
    printf("First word: %s, Second word: %s\n", result[0], result[1]);
    return 0;
}

