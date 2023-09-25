#include "libft.h"
#include <stdio.h>

int main() {
    t_list *element = ft_lstnew("new");
    printf("New element: %s\n", element->content);
    return 0;
}

