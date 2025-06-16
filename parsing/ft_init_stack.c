/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:46:55 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 19:08:08 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

static int	check(t_table *a)
{
	t_list	*temp;

	temp = a->head;
	while (temp != a->tail)
	{
		if (temp->value == a->tail->value)
			return (ft_lstclear(&a->head), 1);
		temp = temp->next;
	}
	if (a->max == NULL || a->max->value < temp->value)
		a->max = temp;
	if (a->min == NULL || a->min->value > temp->value)
		a->min = temp;
	return (0);
}

static int	ft_init_stack2(char *av, t_table *a)
{
	char	**temp_split;
	int		count;

	temp_split = ft_split(av, ' ');
	if (temp_split == NULL)
		return (1);
	count = 0;
	while (temp_split[count] != NULL)
		count++;
	if (ft_init_stack (temp_split, a))
	{
		free_all(temp_split, count);
		return (1);
	}
	free_all(temp_split, count);
	return (0);
}

int	ft_init_stack(char **av, t_table *a)
{
	while (*av != NULL)
	{
		if (ft_wrd_count(*av, ' '))
		{
			if (ft_init_stack2 (*(av++), a))
				return (1);
		}
		else if (a->head == NULL)
		{
			a->head = ft_lstnew(*(av++), NULL);
			if (a->head == NULL)
				return (ft_lstclear(&a->head), 1);
			a->tail = a->head;
		}
		else if (a->head)
		{
			a->tail->next = ft_lstnew (*(av++), a->tail);
			if (a->tail->next == NULL)
				return (ft_lstclear(&a->head), 1);
			a->tail = a->tail->next;
		}
		if (check(a))
			return (ft_lstclear(&a->head), 1);
	}
	return (0);
}
