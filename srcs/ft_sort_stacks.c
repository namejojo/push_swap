/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:47:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/13 22:26:39 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

static int find2(t_list *a, t_list *b, int max)
{
	int	temp_favor;

	if (b->value >= max / 2)
	{
		if (b->value < a->value && b->value >= a->value - max / 2)
			temp_favor = a->value - b->value -1;
		else if (b->value > a->value)
			temp_favor = b->value - a->value;
		else
			temp_favor = max - a->value + b->value;
	}
	else
	{
		if (b->value > a->value && b->value < a->value + max / 2)
			temp_favor = b->value - a->value ;
		else if (b->value < a->value)
			temp_favor = a->value - b->value - 1;
		else 
			temp_favor = a->value - 1 + max - b->value;
	}
	return (temp_favor);
}

int	find(t_list *a, t_list *b, int max, int size)
{
	long	curr_favor;
	int		temp_favor;
	int		ops;
	int		ret;

	ops = 0;
	curr_favor = INT_MAX;
	while (b)
	{
		temp_favor = find2(a, b, max);
		if (temp_favor < curr_favor)
		{
			curr_favor = temp_favor;
			ret = ops;
		}
		b = b->next;
		if (ops < size / 2)
			temp_favor += ops;
		else
			temp_favor += size / 2 - ops % (size / 2);
		ops++;
	}
	return (ret + 1);
}

static void	push_n_organize (t_table *a, t_table *b)
{
	int flag;

	flag = find(a->head, b->head, a->max->value, b->size);
	if (flag <= b->size / 2)
		while (flag-- > 1)
			rb(b);
	else 
		while (flag++ < b->size + 1)
			rrb(b);
	pb(a, b);
	if (b->head->value < b->head->next->value)
		sb(b);
}

void	ft_sort_stack(t_table *a, t_table *b)
{
	if (a->size == 3)
		organize_3(a);
	if (a->size == 2)
	{
		if (a->head->value > a->head->next->value)
			ra(a);
		return ;		
	}
	if (b->head == NULL)
	{
		pb(a, b);
		pb(a, b);
		if (b->head->value < b->head->next->value)
			rb(b);
	}
	if (check_if_sorted(a, b))
	{
		while (a->size > 3)
			push_n_organize(a, b);
		if (a->size == 3)
			organize_3(a);
	}
}
