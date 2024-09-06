#include "../ft_printf.h"

void	*ft_memset(char *dest, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = c;
		i++;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t len)
{
	ft_memset(s, 0, len);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*dst;

	total = count * size;
	dst = malloc(total);
	if (dst == NULL)
		return (dst);
	ft_bzero(dst, total);
	return (dst);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
