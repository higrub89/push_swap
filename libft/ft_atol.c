#include "libft.h"

long    ft_atol(const char *s)
{
    long    result;
    int     sig;

    result = 0;
    sig = 0;
    while (*s == ' ' || *s == '\t' || '\n' || *s == '\r' || *s == '\f' || *s == '\v')
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sig = -1;
        s++;
    }
    while (ft_isdigit(*s))
        result = result * 10 + (*s++ - '0');
    return (result * sig);
}