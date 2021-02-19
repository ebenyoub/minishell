#include "../includes/minishell.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	i = 0;
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while ((d[i] || s[i]) && (n-- > 0))
	{
		if (d[i] != s[i])
			return (d[i] - s[i]);
		else
			i++;
	}
	return (0);
}

char	*ft_strcat(char *s1, char *s2)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (s1[x])
		x++;
	while (s2[y])
	{
		s1[x] = s2[y];
		x++;
		y++;
	}
	s1[x] = '\0';
	return (s1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*d;

	d = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	len;
	int				*area;

	len = size * count;
	if (!(area = malloc(len)))
		return (NULL);
	return (ft_memset(area, '\0', len));
}