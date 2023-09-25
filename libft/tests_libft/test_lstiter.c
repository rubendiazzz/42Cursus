#include "libft.h"
#include <stdio.h>

void print_element(void *content) {
    printf("%s\n", (char*)content);
}

int main() {
    t_list *head = ft_lstnew("first");
    ft_lstadd_back(&head, ft_lstnew("second"));
    ft_lstiter(head, print_element);
    return 0;
}

