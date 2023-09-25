#include "libft.h"
#include <stdio.h>

int main() {
    t_list *head = ft_lstnew("second");
    t_list *new = ft_lstnew("first");
    ft_lstadd_front(&head, new);
    printf("First element: %s\n", head->content);
    return 0;
}

