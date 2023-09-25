#include "libft.h"
#include <stdio.h>

int main() {
    t_list *head = ft_lstnew("first");
    ft_lstadd_back(&head, ft_lstnew("second"));
    ft_lstclear(&head, NULL);
    printf("List after clear: %p\n", (void*)head);
    return 0;
}

