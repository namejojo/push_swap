/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:47:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/09 21:42:07 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// void try1(t_table *a, t_table *b)
// {
	// int	flag;
// 
	// flag = 0;
	// while (flag <= a->avg)
	// {
		// if (a->head->value <= a->avg)
		// {
			// pb(a, b);
			// flag++;
			// if (flag > a->avg)
				// break ;
		// }
		// ra(a);
	// }
	// while ()
	// {
		//
	// }
// }

static void	organize_3(t_table *a)
{
	int temp;

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

static void	push_n_organize (t_table *a, t_table *b)
{
	
}

void	ft_sort_stack(t_table *a, t_table *b)
{
	int	a_size;
	
	a_size = ft_lstsize(a->head);
	if (a_size == 3)
		organize_3(a);
	while (a_size > 3)
	{
		if (check_if_sorted(a, b))
			push_n_organize(a, b);
		if (--a_size == 3)
			organize_3(a);
	}
	while (b->head != NULL)
		push_n_organize(b, a);
	print_value(a, b); // checking if correct
}
