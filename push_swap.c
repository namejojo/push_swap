/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:47:07 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 18:28:50 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_table	*init_table(t_table *a)
{
	if (a == NULL)
		return (NULL);	
	a->head = NULL;
	a->tail = NULL;
	a->max = NULL;
	a->min = NULL;
	a->size = 0;
	return (a);
}

void	mark_bigger_count(t_table *a)
{
	int		count;
	t_list	*temp;
	t_list	*value;

	value = a->head;
	while (value)
	{
		temp = value;
		count = 0;
		while (temp->value != 1)
		{
			if (temp->value > value->value)
				count++;
			temp = temp->next;
			if (temp == NULL)
				temp = a->head;
		}
		if (value->value == 1)
			count = a->max->value;
		value->flag = count + 2;
		value = value->next;
	}
}

void print_value (t_table *a, t_table *b) // delete
{
	t_list	*temp;
	t_list	*temp2;
	
	temp = a->head;
	temp2 = b->head;
	ft_printf("\nA\tB");
	ft_printf("\n");
	while (temp != NULL || temp2 != NULL)
	{
		if (temp)
		{
			ft_printf("%d", (int)temp->value);
			temp = temp->next;
		}
		else
			ft_printf("   ");
		ft_printf("\t   ");
		if (temp2)
		{
			ft_printf("%d\n", (int)temp2->value);
			temp2 = temp2->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n");
	ft_printf("--------------------------------\n");
}

static t_list	*biggest_one(t_table *ta)
{
	t_list	*a;
	t_list	*ret;
	
	ret = ta->min;
	a = ta->head;
	while (a)
	{
		if (a->value > ret->value && a->flag == 1)
			ret = a;
		a = a->next;
	}
	// a = ta->head;
	// while (a)
	// {
	// 	if (a->value > ret->value && a->flag == 1)
	// 		ret = a;
	// 	a = a->next;
	// }
	return (ret);
}

static void	get_last_order(t_table *a)
{
	t_list	*hold;
	t_list	*temp;
	
	hold = biggest_one(a);
	temp = hold->next;
	while (temp != a->min)
	{
		if (temp == NULL)
			temp = a->head;
		if (temp == a->min)
			return ;
		if (temp->flag != 1 && temp->value > hold->value)
			temp->flag = 1;
		temp = temp->next;
	}
}

void	get_order(t_table *a)
{
	t_list	*comp;
	t_list	*hold;
	int		one;

	one = biggest_one(a)->value;
	comp = biggest_one(a)->next;
	a->min->flag = 1;
	hold = a->max;
	while (comp != a->min)
	{
		if (comp == NULL)
			comp = a->head;
		if (comp == a->min)
			break ;
		if ((comp->flag != 0 && comp->flag != 1) && comp->flag >= hold->flag && comp->value < hold->value && comp->value > one)
			hold = comp;
		comp = comp->next;
	}
	if (hold != a->max)
		hold->flag = 1;
}

int	main(int ac, char **av)
{
	t_table	*a;
	t_table	*b;

	if (ac < 2)
		return (0);
	a = init_table(malloc(sizeof(t_table)));
	if (a == NULL)
		return (write(2, "Error\n", 7));
	b = init_table(malloc(sizeof(t_table)));
	if (b == NULL)
		return (write(2, "Error\n", 7));
	if (ft_init_stack(++av, a))
		return (free (a), write(2, "Error\n", 7));
	format_stack(a);
	get_last_order(a);
	ft_sort_stack(a, b);
	ft_lstclear(&a->head);
	free (a);
	free (b);
}
