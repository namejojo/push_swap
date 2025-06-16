/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:47:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 18:58:27 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	organize_3(t_table *a)
{
	int	temp;

	temp = a->head->value;
	if (temp > a->head->next->value && temp > a->tail->value)
	{
		if (a->head->next->value < a->tail->value)
			return (ra(a));
		return (sa(a), rra(a));
	}
	if (temp < a->head->next->value && temp < a->tail->value)
	{
		if (a->head->next->value > a->tail->value)
			return (ra(a), sa(a), rra(a));
		return ;
	}
	if (temp < a->tail->value)
		return (sa(a));
	rra(a);
}

void	listify(t_list *b)
{
	t_list	*next;

	next = b->next;
	while (next)
	{
		next->previous = b;
		b = b->next;
		next = b->next;
	}
}

void	ft_sort_stack(t_table *a, t_table *b)
{
	if (a->size == 3)
		return (organize_3(a));
	if (a->size == 2 && a->head->value > a->head->next->value)
		return (ra(a));
	organize_to_b(a, b);
	if (a->size == 3)
		organize_3(a);
	listify(b->head);
	organize_to_a(a, b);
}
