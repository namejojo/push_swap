/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:47:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/03 00:02:49 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// static int	check_zeros(t_list *a)
// {
// 	while (a)
// 	{
// 		if (a->flag != 1)
// 			return (1);
// 		a = a->next;
// 	}
// 	return (0);
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

// t_organize find_b_target(t_list *a, t_list *b, t_list *min)
// {
// 	t_organize	ret;
// 	int			ops;

// 	ops = -1;
// 	ret.target = min;
// 	ret.target_max = min;
// 	ret.flag = 0;
// 	while (b && ++ops > -1)
// 	{
// 		if (b->value <= a->value && b->value >= ret.target->value)
// 		{
// 			ret.target = b;
// 			ret.target_ops = ops;
// 			ret.flag = 1;
// 		}
// 		if (b->value > ret.target_max->value)
// 		{
// 			ret.target_max = b;
// 			ret.target_max_ops = ops;
// 		}
// 		b = b->next;
// 	}
// 	return (ret);
// }


// static t_organize	pushing_to_b (t_table *a, t_table *b)
// {
// 	t_organize	temp;
// 	t_organize	curr;
// 	t_list		*la;
// 	int			ops;

// 	ops = 0;
// 	la = a->head;
// 	curr.target_ops = 10000000;
// 	curr.target_max_ops = 10000000;
// 	while (la)
// 	{
// 		temp = find_b_target(la, b->head, a->min);
// 		if (temp.flag == 0)
// 		{
// 			temp.target = temp.target_max;
// 			temp.target_ops = temp.target_max_ops;
// 		}
// 		if (temp.target_ops + ++ops < curr.target_ops)
// 		{
// 			curr = temp;
// 			curr.node_to_move_ops = ops;
// 			curr.node_to_move = la;
// 		}
// 		la = la->next;
// 	}
// 	return (curr);
// }

// static void	put_b(t_table *a, t_table *b, t_organize curr)
// {
// 	if (curr.node_to_move_ops < a->size / 2)
// 		while (curr.node_to_move->value != a->head->value)
// 			ra(a);
// 	else
// 		while (curr.node_to_move->value != a->head->value)
// 			rra(a);
// 	print_value(a, b);
// 	pb(a, b);
// }

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

static t_organize	pushing_to_a (t_table *a, t_table *b)
{
	t_organize	temp;
	t_organize	curr;
	int			ops;

	ops = 0;
	curr.target_ops = 10000000;
	curr.target_max_ops = 10000000;
	temp = find_a_target(b->head, a->head, a->max);
	if (temp.flag == 0)
	{
		temp.target = temp.target_max;
		temp.target_ops = temp.target_max_ops;
	}
	if (temp.target_ops + ++ops < curr.target_ops)
	{
		curr = temp;
		curr.node_to_move_ops = ops;
		curr.node_to_move = b->head;
	}
	return (curr);
}

static int	lower_count(t_list *a, int max)
{
	int	ret;

	ret = 0;
	while (a)
	{
		ret = ret + (a->value <= max);
		a = a->next;
	}
	return (ret);	
}

static void	find_closeste_value(t_table *a, int max)
{
	t_list	*la;
	t_list	*la2;
	int		loops;
	int		loops2;

	loops2 = 1;
	loops = 0;
	la = a->head;
	la2 = a->tail;
	while (la && la->value > max)
	{
		loops++;
		la = la->next;
	}
	while (la2 && la2->value > max)
	{
		loops2++;
		la2 = la2->previous;
	}
	if (loops < loops2)
		while (loops--)
			ra(a);
	else
		while (loops2--)
			rra(a);
	
}

static void	organize_all(t_table *a, t_table *b)
{
	int	min;
	int	max;
	int	loop;
	int	count;

	loop = 0;
	while (a->size > 3 && ++loop)
	{
		max = (a->max->value / 10) * 2 * loop;
		min = max - (a->max->value / 10);
		count = lower_count(a->head, max);
		while (count-- > 0)
		{
			if (a->size <= 3)
				break ;
			find_closeste_value(a, max);
			if (a->head->value <= min)
				pb(a, b), rb(b);
			else
				pb(a, b);
		}
	}
}

// static void	push_two(t_table *a)
// {
// 	t_list	*la;
// 	t_list	*la2;
// 	int		loops;
// 	int		loops2;

// 	loops2 = 1;
// 	loops = 0;
// 	la = a->head;
// 	la2 = a->tail;
// 	while (la && la->flag == 1)
// 	{
// 		loops++;
// 		la = la->next;
// 	}
// 	while (la2 && la2->flag == 1)
// 	{
// 		loops2++;
// 		la2 = la2->previous;
// 	}
// 	if (loops < loops2)
// 		while (loops--)
// 			ra(a);
// 	else
// 		while (loops2--)
// 			rra(a);
// }

int	higher_count(t_list *b, int min)
{
	int	ret;

	ret = 0;
	while (b)
	{
		ret = ret + (b->value >= min);
		b = b->next;
	}
	return (ret);	
}

static void	find_closeste_bigger_value(t_table *a, int min)
{
	t_list	*la;
	t_list	*la2;
	int		loops;
	int		loops2;

	loops2 = 1;
	loops = 0;
	la = a->head;
	la2 = a->tail;
	while (la && la->value < min)
	{
		loops++;
		la = la->next;
	}
	while (la2 && la2->value < min)
	{
		loops2++;
		la2 = la2->previous;
	}
	ft_printf("we found %d and %d\n", la->value, la2->value);
	if (loops < loops2)
		while (loops--)
			ra(a);
	else
		while (loops2--)
			rra(a);
	
}

void	ft_sort_stack (t_table *a, t_table *b)
{
	int	min;
	int	loop;
	int	count;

	if (a->size == 3)
		return (organize_3(a));
	if (a->size == 2 && a->head->value > a->head->next->value)
		return (ra(a));
	organize_all(a, b);
	if (a->size == 3)
		organize_3(a);
	loop = 10;
	while (b->head != NULL)
	{
		loop = loop - 2;
		min = (a->max->value / 10) * loop;
		count = higher_count(b->head, min);
		while (count-- > 0 && b->head != NULL)
		{
			print_value(a, b);
			find_closeste_bigger_value(b, min);
			put_a(a, b, pushing_to_a (a, b));
		}
	}
	if (a->head->value < a->size / 2)
		while (a->tail != a->max)
			rra(a);
	else
		while (a->tail != a->max)
			ra(a);
}
