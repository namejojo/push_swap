/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:57:41 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 19:03:45 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_check(char *str)
{
	int	count;

	count = 0;
	str = skip_spaces(str);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (1);
	while (*str == '0' && *str)
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
		count++;
		if (count > 10)
			return (1);
	}
	return (0);
}

t_list	*ft_lstnew(char *content, t_list *last)
{
	t_list	*new;
	long	temp;

	if (content == NULL || ft_check(content))
		return (NULL);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	temp = ft_atol(content);
	if (temp > INT_MAX || temp < INT_MIN)
		return (free(new), NULL);
	new->value = temp;
	new->next = NULL;
	new->previous = last;
	new->flag = 10;
	return (new);
}
