#include "ft_printf.h"

int main()
{
  char a = 'b';
  printf("%c %c %c \n", a, a, a);
  ft_printf("%c %c %c \n", a, a, a);
}
