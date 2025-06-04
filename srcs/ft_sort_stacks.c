/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:47:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/04 11:31:46 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_target	find_favor(t_target ret, t_table *ta, t_table *tb)
{
	int		location;
	t_list	*a;
	t_list	*b;

	a = ta->head;
	b = tb->head;
	location = 0;
	while (a && a->value != ret.to_move->value)
	{
		location++;
		a = a->next;
	}
	ret.to_move_favor = location;
	if (location > ta->size / 2)
		ret.to_move_favor = ta->size - location;
	ret.to_move_location = location;
	location = 0;
	while (b && b->value != ret.target->value)
	{
		location++;	
		b = b->next;
	}
	ret.target_favor = location;
	if (location > tb->size / 2)
		ret.target_favor = tb->size - location;
	ret.target_location = location;
	return (ret);
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

static void	really_push_b(t_table *a, t_table *b, t_target curr)
{
	if (curr.to_move_location < a->size / 2 && curr.target_location <= b->size / 2)
		while (curr.to_move->value != a->head->value && b->head->value != curr.target->value)
			rr(a, b);
	else if (!(curr.to_move_location < a->size / 2) && !(curr.target_location <= b->size / 2))
		while (curr.to_move->value != a->head->value && b->head->value != curr.target->value)
			rrr(a, b);
	if (curr.to_move_location < a->size / 2)
		while (curr.to_move->value != a->head->value)
			ra(a);
	else
		while (curr.to_move->value != a->head->value)
			rra(a);
	if (curr.target_location > b->size / 2)
		while (b->head->value != curr.target->value)
			rrb(b);
	else
		while (b->head->value != curr.target->value)
			rb(b);
	pb(a, b);
}

static t_target	find_b_target(t_list *a, t_table *ta, t_table *tb)
{
	t_list		*b;
	t_target	ret;
	t_target	ret_flag;
	int			flag;

	b = tb->head;
	ret.target = ta->min;
	ret_flag.target = ta->min;
	flag = 0;
	while (b)
	{
		flag += (b->value <= a->value && b->value >= ret.target->value);
		if (b->value <= a->value && b->value >= ret.target->value)
			ret.target = b;
		if (b->value >= ret_flag.target->value)
			ret_flag.target = b;
		b = b->next;
	}
	ret.to_move = a;
	ret_flag.to_move = a;
	if (flag == 0)
		return (find_favor(ret_flag, ta, tb));
	return (find_favor(ret, ta, tb));
}

static void	push_to_b(t_table *ta, t_table* tb)
{
	t_list		*a;
	t_target	target;
	t_target	temp;

	a = ta->head;
	target = find_b_target(a, ta, tb);
	while (a)
	{
		temp = find_b_target(a, ta, tb);
		if (target.target_favor + target.to_move_favor >= temp.target_favor + temp.to_move_favor)
			target = temp;
		a = a->next;
	}
	really_push_b (ta, tb, target);
}

static void	really_push_a(t_table *a, t_table *b, t_target curr)
{
	if (curr.to_move_location < b->size / 2 && curr.target_location <= a->size / 2)
		while (curr.to_move->value != b->head->value && a->head->value != curr.target->value)
			rr(a, b);
	else if (!(curr.to_move_location < b->size / 2) && !(curr.target_location <= a->size / 2))
		while (curr.to_move->value != b->head->value && a->head->value != curr.target->value)
			rrr(a, b);
	if (curr.to_move_location < b->size / 2)
		while (curr.to_move->value != b->head->value)
			rb(b);
	else
		while (curr.to_move->value != b->head->value)
			rrb(b);
	if (curr.target_location > a->size / 2)
		while (a->head->value != curr.target->value)
			rra(a);
	else
		while (a->head->value != curr.target->value)
			ra(a);
	pa(a, b);
}

static t_target	find_a_target(t_list *b, t_table *ta, t_table *tb)
{
	t_list		*a;
	t_target	ret;
	t_target	ret_flag;
	int			flag;

	a = ta->head;
	ret.target = ta->max;
	ret_flag.target = ta->max;
	flag = 0;
	while (a)
	{
		flag += (a->value >= b->value && a->value <= ret.target->value);
		if (a->value >= b->value && a->value <= ret.target->value)
			ret.target = a;
		if (a->value <= ret_flag.target->value)
			ret_flag.target = a;
		a = a->next;
	}
	ret.to_move = b;
	ret_flag.to_move = b;
	if (flag == 0)
		return (find_favor(ret_flag, tb, ta));
	return (find_favor(ret, tb, ta));
}

static void	push_to_a(t_table *ta, t_table* tb)
{
	print_value (ta, tb);
	really_push_a (ta, tb, find_a_target(tb->head, ta, tb));
}

static t_list	*find_b_max(t_table *b)
{
	t_list	*ret;
	t_list	*temp;

	ret = b->head;
	temp = b->head->next;
	while (temp)
	{
		if (temp->value > ret->value)
			ret = temp;
		temp = temp->next;
	}
	return (ret);
}

void	ft_sort_stack (t_table *a, t_table *b)
{
	if (a->size == 3)
		return (organize_3(a));
	if (a->size == 2 && a->head->value > a->head->next->value)
		return (ra(a));
	pb(a, b);
	pb(a, b);
	while (a->size > 3)
		push_to_b(a, b);
	if (a->size == 3)
		organize_3(a);
	b->max = find_b_max(b);
	{
		if (b->head->value < b->size / 2)
			while (b->head != b->max)
				rb(b);
		else
			while (b->head != b->max)
				rrb(b);
	}
	while (b->head != NULL)
		push_to_a(a, b);
	if (a->head->value < a->size / 2)
		while (a->head != a->min)
			rra(a);
	else
		while (a->head != a->min)
			ra(a);
}
