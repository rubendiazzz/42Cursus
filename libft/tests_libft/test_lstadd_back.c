#include "libft.h"
#include <stdio.h>

int main() {
    t_list *head = ft_lstnew("first");
    t_list *new = ft_lstnew("second");
    ft_lstadd_back(&head, new);
    printf("Last element: %s\n", ft_lstlast(head)->content);
    return 0;
}

