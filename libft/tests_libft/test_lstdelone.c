#include "libft.h"
#include <stdio.h>

int main() {
    t_list *element = ft_lstnew("single");
    ft_lstdelone(element, NULL);
    printf("Element after delete: %p\n", (void*)element);
    return 0;
}

