/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:40:30 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 19:15:54 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	push_to_b(t_table *a, t_table *b, int max, int min)
{
	while (a->size > 3)
	{
		if (a->head->value <= min && a->head->value <= a->max->value - 3)
		{
			pb(a, b);
			rb(b);
			return ;
		}
		else if (a->head->value <= max && a->head->value <= a->max->value - 3)
			return (pb(a, b));
		else
			ra(a);
	}
}

void	organize_to_b(t_table *a, t_table *b)
{
	int	min;
	int	max;
	int	count;
	int	loop;
	int	divider;

	if (a->max->value >= 100)
		divider = a->max->value / 50 + 6;
	else if (a->max->value >= 50)
		divider = a->max->value / (a->max->value / 10);
	else if (a->max->value >= 10)
		divider = a->max->value / (a->max->value / 2);
	else
		divider = (a->max->value < 7) * 2 + 2;
	min = -a->max->value / divider;
	max = 0;
	count = a->max->value / (divider / 2);
	while (a->size > 3)
	{
		loop = 0;
		max += count;
		min += count;
		while (++loop <= count && a->size > 3)
			push_to_b(a, b, max, min);
	}
}

int	find_closeste(t_table *tb, int skip)
{
	int		from_up;
	int		from_down;
	t_list	*b;

	from_up = 0;
	from_down = 1;
	b = tb->head;
	while (b != tb->tail && b->value < skip)
	{
		from_up++;
		fflush(stdout);
		b = b->next;
	}
	fflush(stdout);
	b = tb->tail;
	while (b != tb->head && b->value < skip)
	{
		from_down++;
		fflush(stdout);
		b = b->previous;
	}
	if (from_down < from_up)
		return (from_down * -1);
	return (from_up);
}

void	push_to_a(t_table *a, t_table *b, int location)
{
	if (location < 0)
		while (location++)
			rrb(b);
	else
		while (location--)
			rb(b);
	pa(a, b);
}

void	organize_to_a(t_table *a, t_table *b)
{
	int	location;
	int	limit;

	limit = b->size - 1;
	while (b->head)
	{
		location = find_closeste(b, limit);
		push_to_a (a, b, location);
		if (a->head->value != a->head->next->value - 1)
		{
			location = find_closeste(b, limit);
			push_to_a (a, b, location);
			if (a->head->value > a->head->next->value)
				sa(a);
			limit -= 2;
		}
		else
			limit--;
	}
}
