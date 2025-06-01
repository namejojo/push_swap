/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:47:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/01 23:58:09 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_zeros(t_list *a)
{
	while (a)
	{
		if (a->flag != 1)
			return (1);
		a = a->next;
	}
	return (0);
}

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

static void	put_b(t_table *a, t_table *b, t_organize curr)
{
	if (curr.node_to_move_ops < a->size / 2 && curr.target_ops <= b->size / 2)
		while (curr.node_to_move->value != a->head->value && b->head->value != curr.target->value)
			rr(a, b);
	else if (!(curr.node_to_move_ops < a->size / 2) && !(curr.target_ops <= b->size / 2))
		while (curr.node_to_move->value != a->head->value && b->head->value != curr.target->value)
			rrr(a, b);
	if (curr.node_to_move_ops < a->size / 2)
		while (curr.node_to_move->value != a->head->value)
			ra(a);
	else
		while (curr.node_to_move->value != a->head->value)
			rra(a);
	if (curr.target_ops <= b->size / 2)
		while (b->head->value != curr.target->value)
			rb(b);
	else
		while (b->head->value != curr.target->value)
			rrb(b);
	pb(a, b);
}

static void	put_a(t_table *a, t_table *b, t_organize curr)
{
	if (curr.node_to_move_ops < b->size / 2 && curr.target_ops < a->size / 2)
		while (curr.node_to_move->value != b->head->value && a->head->value != curr.target->value)
			rr(a, b);
	else if (!(curr.node_to_move_ops < b->size / 2) && !(curr.target_ops < a->size / 2))
		while (curr.node_to_move->value != b->head->value && a->head->value != curr.target->value)
			rrr(a, b);
	if (curr.node_to_move_ops < b->size / 2)
		while (curr.node_to_move->value != b->head->value)
			rb(b);
	else 
		while (curr.node_to_move->value != b->head->value)
			rrb(b);
	if (curr.target_ops < a->size / 2)
		while (a->head->value != curr.target->value)
			ra(a);
	else
		while (a->head->value != curr.target->value)
			rra(a);
	b->head->flag = 1;
	pa(a, b);
}
t_organize find_a_target(t_list *b, t_list *a, t_list *max)
{
	t_organize	ret;
	int			ops;

	ops = -1;
	ret.target = max;
	ret.target_max = max;
	ret.flag = 0;
	while (a && ++ops > -1)
	{
		if (a->value >= b->value && a->value <= ret.target->value && a->flag == 1)
		{
			ret.target = a;
			ret.target_ops = ops;
			ret.flag = 1;
		}
		if (a->value < ret.target_max->value && a->flag == 1)
		{
			ret.target_max = a;
			ret.target_max_ops = ops;
		}
		a = a->next;
	}
	return (ret);
}

static t_organize	pushing_to_b (t_table *a, t_table *b)
{
	t_organize	temp;
	t_organize	curr;
	t_list		*la;
	int			ops;

	ops = 0;
	la = a->head;
	curr.target_ops = 10000000;
	curr.target_max_ops = 10000000;
	while (la)
	{
		if (la->flag != 1)
		{
			temp = find_b_target(la, b->head, a->min);
			if (temp.flag == 0)
			{
				temp.target = temp.target_max;
				temp.target_ops = temp.target_max_ops;
			}
			if (temp.target_ops + ++ops < curr.target_ops)
			{
				curr = temp;
				curr.node_to_move_ops = ops;
				curr.node_to_move = la;
			}
		}
		la = la->next;
	}
	return (curr);
}

static t_organize	pushing_to_a (t_table *a, t_table *b)
{
	t_organize	temp;
	t_organize	curr;
	t_list		*lb;
	int			ops;

	ops = 0;
	lb = b->head;
	curr.target_ops = 10000000;
	curr.target_max_ops = 10000000;
	while (lb)
	{
		temp = find_a_target(lb, a->head, a->max);
		if (temp.flag == 0)
		{
			temp.target = temp.target_max;
			temp.target_ops = temp.target_max_ops;
		}
		if (temp.target_ops + ++ops < curr.target_ops)
		{
			curr = temp;
			curr.node_to_move_ops = ops;
			curr.node_to_move = lb;
		}
		lb = lb->next;
	}
	return (curr);
}

static void	organize_all(t_table *a, t_table *b)
{
	t_organize	org_to_b;
	t_organize	org_to_a;
	
	org_to_a = pushing_to_a (a, b);
	org_to_b = pushing_to_b (a, b);

	if (check_zeros(a->head) && org_to_b.target_ops + org_to_b.node_to_move_ops
	 < org_to_a.target_ops + org_to_a.node_to_move_ops)
	 {
		ft_printf("this %d goes here %d\n", org_to_b.node_to_move->value, org_to_b.target->value);
		ft_printf("instead of this %d going here %d\n", org_to_a.node_to_move->value, org_to_a.target->value);
		put_b(a, b, org_to_b);
	 }
	else
	{
		ft_printf("this %d goes here %d\n", org_to_a.node_to_move->value, org_to_a.target->value);
		ft_printf("instead of this %d going here %d\n", org_to_b.node_to_move->value, org_to_b.target->value);
		put_a(a, b, org_to_a);
	}
	 print_value(a, b);
}

void	ft_sort_stack (t_table *a, t_table *b)
{
	if (a->size == 3)
		return (organize_3(a));
	if (a->size == 2 && a->head->value > a->head->next->value)
		return (ra(a));
	if (check_zeros(a->head))
	{
		while (check_zeros(a->head) && a->head->flag == 1)
			ra(a);
		pb(a, b);
	}
	if (check_zeros(a->head))
	{
		while (check_zeros(a->head) && a->head->flag == 1)
			ra(a);
		pb(a, b);
	}
	print_value(a, b);
	while (a->size > 3 && check_zeros(a->head))
		organize_all(a, b);
	if (a->size == 3)
		organize_3(a);
	while (b->head != NULL)
		put_a(a, b, pushing_to_a (a, b));
	if (a->head->value < a->size / 2)
		while (a->tail != a->max)
			rra(a);
	else
		while (a->tail != a->max)
			ra(a);
}
