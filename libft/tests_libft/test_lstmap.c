#include "libft.h"
#include <stdio.h>

t_list *to_uppercase(t_list *elem) {
    char *content = (char*)elem->content;
    while (*content) {
        *content = toupper(*content);
        content++;
    }
    return elem;
}

int main() {
    t_list *head = ft_lstnew("first");
    ft_lstadd_back(&head, ft_lstnew("second"));
    t_list *new_head = ft_lstmap(head, to_uppercase);
    printf("Transformed first element: %s\n", new_head->content);
    return 0;
}

