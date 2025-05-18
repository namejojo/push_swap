/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:47:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/18 03:41:52 by jlima-so         ###   ########.fr       */
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

t_organize find_b_target(t_list *a, t_list *b, t_list *min)
{
	t_organize	ret;
	int			ops;

	ops = -1;
	ret.target = min;
	ret.target_max = min;
	ret.flag = 0;
	while (b && ++ops > -1)
	{
		if (b->value <= a->value && b->value >= ret.target->value)
		{
			ret.target = b;
			ret.target_ops = ops;
			ret.flag = 1;
		}
		if (b->value > ret.target_max->value)
		{
			ret.target_max = b;
			ret.target_max_ops = ops;
		}
		b = b->next;
	}
	return (ret);
}

static void	push_n_organize (t_table *a, t_table *b)
{
	t_organize	temp;
	t_organize	curr;
	t_list		*la;
	int			ops;

	ops = 0;
	la = a->head;
	curr.target_ops = INT_MAX;
	while (la)
	{
		temp = find_b_target(la, b->head, a->min);
		if (temp.flag == 0)
		{
			temp.target = temp.target_max;
			temp.target_ops = temp.target_max_ops;
		}
		if (temp.target_ops + ops++ < curr.target_ops)
		{
			curr = temp;
			curr.target_max_ops = ops;
			curr.target_max = la;
		}
		la = la->next;
	}
	if (curr.target_max_ops < b->size / 2)
		while (curr.target_max->value != a->head->value)
			ra(a);
	else
		while (curr.target_max->value != a->head->value)
			rra(a);
	if (curr.target_ops < b->size / 2)
		while (b->head->value != curr.target->value)
			rb(b);
	else
		while (b->head->value != curr.target->value)
			rrb(b);
	pb(a, b);
}

t_organize find_a_target(t_list *a, t_list *b, t_list *max)
{
	t_organize	ret;
	int			ops;

	ops = -1;
	ret.target = max;
	ret.target_max = max;
	ret.flag = 0;
	while (a && ++ops > -1)
	{
		if (a->value >= b->value && a->value <= ret.target->value)
		{
			ret.target = a;
			ret.target_ops = ops;
			ret.flag = 1;
		}
		if (a->value < ret.target_max->value)
		{
			ret.target_max = a;
			ret.target_max_ops = ops;
		}
		a = a->next;
	}
	return (ret);
}

static void	pull_n_organize (t_table *a, t_table *b)
{
	t_organize	temp;
	t_organize	curr;
	t_list		*lb;
	int			ops;

	ops = 0;
	lb = b->head;
	curr.target_ops = INT_MAX;
	while (lb)
	{
		temp = find_a_target(a->head, lb, a->max);
		if (temp.flag == 0)
		{
			temp.target = temp.target_max;
			temp.target_ops = temp.target_max_ops;
		}
		if (temp.target_ops + ops++ < curr.target_ops)
		{
			curr = temp;
			curr.target_max_ops = ops;
			curr.target_max = lb;
		}
		lb = lb->next;
	}
	if (curr.target_max_ops < b->size / 2)
		while (curr.target_max->value != b->head->value)
			rb(b);
	else
		while (curr.target_max->value != b->head->value)
			rrb(b);
	if (curr.target_ops < b->size / 2)
		while (a->head->value != curr.target->value)
			ra(a);
	else
		while (a->head->value != curr.target->value)
			rra(a);
	pa(a, b);
}

void	ft_sort_stack (t_table *a, t_table *b)
{
	if (a->size == 3)
		return (organize_3(a));
	if (a->size == 2 && a->head->value > a->head->next->value)
		return (ra(a));
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
	while (b->head)
		pull_n_organize(a, b);
	// print_value(a, b);
		if (a->head->value < a->size / 2)
		while (a->tail != a->max)
			rra(a);
	else
		while (a->tail != a->max)
			ra(a);
	// print_value(a, b);
}
