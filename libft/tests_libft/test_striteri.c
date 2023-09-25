#include "libft.h"
#include <stdio.h>

void to_uppercase(unsigned int i, char *c) {
    if (i % 2 == 0) *c = toupper(*c);
}

int main() {
    char str[] = "hello";
    ft_striteri(str, to_uppercase);
    printf("Transformed string: %s\n", str);
    return 0;
}

