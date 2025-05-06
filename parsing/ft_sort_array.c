/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:46:55 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/06 17:56:15 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// static int	*ft_atoi_pointer(int ac, char **av)
// {
	// int	*ret;
	// int	ind;
// 
	// ret = malloc(sizeof(int) * ac - 2);
	// if (ret == NULL)
		// return (NULL);
	// ind = -1;
	// while (av[++ind + 1] != NULL)
	// {
		// if (ft_check(av[ind + 1]))
			// return (free(ret), NULL);
		// ret[ind] = ft_atoi(av[ind + 1]);
	// }
	// return (ret);
// }

static int	ft_wrd_count(char *str, char c)
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
		if (count > 1)
			return (1);
	}
	return (0);
}

static int function (char *av, t_table *a)
{
	char	**temp_split;
	int		count;

	count = 0;
	temp_split = ft_split(av, ' ');
	if (temp_split == NULL)
		return (1);
	if (ft_format_array (temp_split, a))
		return (1);
	while (temp_split[count] != NULL)
		count++;
	free_all(temp_split, count);
	return (0);
}

static int	dup_check(t_table *a)
{
	t_list	*temp;

	temp = a->head;
	while (temp != a->tail)
	{
		if (temp->value == a->tail->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_format_array(char **av, t_table *a)
{
	while (*av != NULL && ++a->size > -1)
	{
		if (ft_wrd_count(*av, ' '))
		{
			if (function (*(av++), a))
				return (1);
		}
		else if (a->head == NULL)
		{
			a->head = ft_lstnew(*(av++), NULL);
			if (a->head == NULL)
				return (1);
			a->tail = a->head;
		}
		else if (a->head)
		{
			a->tail->next = ft_lstnew (*(av++), a->tail);
			if (a->tail->next == NULL)
				return (ft_lstclear(&a->head), 1);
			a->tail = a->tail->next;
		}
		if (dup_check(a))
			return (ft_lstclear(&a->head), 1);			
	}
	return (0);
}
