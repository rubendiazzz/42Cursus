#include "libft.h"
#include <stdio.h>

int main() {
    t_list *head = ft_lstnew("first");
    ft_lstadd_back(&head, ft_lstnew("second"));
    printf("List size: %d\n", ft_lstsize(head));
    return 0;
}

