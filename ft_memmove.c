#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
    void	*tmp;

    if (!dst && !src)
        return (0);
    tmp = dst;
    if (dst < src)
        while (len--)
            *(char *)dst++ = *(char *)src++;
    else
    {
        dst += len - 1;
        src += len - 1;
        while (len--)
            *(char *)dst-- = *(char *)src--;
    }
    return (tmp);
}
