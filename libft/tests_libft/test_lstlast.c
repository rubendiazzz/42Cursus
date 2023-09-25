#include "libft.h"
#include <stdio.h>

int main() {
    t_list *head = ft_lstnew("first");
    ft_lstadd_back(&head, ft_lstnew("second"));
    printf("Last element: %s\n", ft_lstlast(head)->content);
    return 0;
}

