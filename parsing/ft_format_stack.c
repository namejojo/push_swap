/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:25:57 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/07 17:21:59 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_lstpass(t_list *temp)
{
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		temp->value = temp->value + INT_MAX;
		temp = temp->next;
	}
}

void	format_stack(t_table *a)
{
	t_list	*curr_lst;
	t_list	*temp;
	int		last_value;
	int		ind;

	ft_lstpass(a->head);
	last_value = -1;
	ind = -1;
	while (++ind < a->tail->index)
	{
		temp = a->head;
		while (temp != NULL)
		{
			if (temp->value > last_value && temp->value < curr_lst->value)
				curr_lst = temp;
			temp = temp->next;
		}
		last_value = curr_lst->value;
		curr_lst->value = ind;
	}
}
