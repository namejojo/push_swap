#include "libft.h"

static int	ft_wrd_count(char *str, char c)
{
	int	ind;
	int	count;

	count = 0;
	ind = 0;
	while (str[ind])
	{
		if (str[ind] != c && (str[ind + 1] == '\0' || str[ind + 1] == c))
			count++;
		ind++;
		if (count > 1)
			return (1);
	}
	return (0);
}

int main(void)
{
	ft_printf("%d", ft_wrd_count("123 ", ' '));
}