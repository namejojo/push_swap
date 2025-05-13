/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:25:57 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/13 18:45:56 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_lstadd(t_table *a)
{
	t_list	*temp;

	temp = a->head;
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		temp->value = temp->value + 2147483650;
		temp = temp->next;
	}
}

void	format_stack(t_table *a)
{
	t_list	*curr_lst;
	t_list	*temp;
	long	ind;
	int		size;

	ft_lstadd(a);
	ind = 0;
	size = ft_lstsize(a->head);
	while (++ind < size)
	{
		curr_lst = a->max;
		temp = a->head;
		while (temp != NULL)
		{
			if (temp->value >= ind && temp->value < curr_lst->value)
				curr_lst = temp;
			temp = temp->next;
		}
		curr_lst->value = ind;
	}
	a->size = ft_lstsize(a->head);
	a->max->value = a->size;
}
