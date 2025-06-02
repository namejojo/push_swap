/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:50:55 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/06 16:54:38 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_str_count(char *str, char c)
{
	int	ind;
	int	count;

	count = 0;
	ind = 0;
	while (str[ind])
	{
		if (str[ind] != c && (str[ind + 1] == '\0'
				|| str[ind + 1] == c))
			count++;
		ind++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, char c)
{
	char	*src;
	char	*dest;
	int		size;

	size = 0;
	while (s[size])
	{
		if (s[size] == c)
			break ;
		size++;
	}
	if (s == NULL)
		return (NULL);
	src = (char *)s;
	dest = ft_calloc(size + 1, 1);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, size + 1);
	dest = ft_memcpy(dest, src, size);
	return (dest);
}

void	*free_all(char **strs, int count)
{
	int	ind;

	ind = -1;
	while (++ind < count)
		free (strs[ind]);
	free (strs);
	return (NULL);
}

static char	**alloc_mem(int str_count)
{
	char	**ret;

	ret = ft_calloc((str_count + 1) * sizeof(char *), 1);
	if (ret == NULL)
		return (NULL);
	ret[str_count] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	t_split	data;

	if (s == NULL)
		return (NULL);
	data.indv = 0;
	data.str = (char *)s;
	data.str_count = ft_str_count(data.str, c);
	data.ret = alloc_mem(data.str_count);
	if (data.ret == NULL)
		return (NULL);
	while (data.str_count-- > 0)
	{
		while (*data.str == c && *data.str)
			data.str++;
		data.ret[data.indv] = ft_strndup(data.str, c);
		if (data.ret[data.indv] == NULL && data.indv != data.str_count)
			return (free_all(data.ret, data.indv));
		data.indv++;
		while (*data.str != c && *data.str)
			data.str++;
	}
	return (data.ret);
}
