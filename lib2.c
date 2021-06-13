#include "include/push_swap.h"

size_t	ft_strlen(const char *str)
{
	const char	*ptr;
	size_t		i;

	ptr = str;
	i = 0;
	while (ptr[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;

	if (s1 == s2 || n == 0)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
