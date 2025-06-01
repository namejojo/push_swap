/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:47:07 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/01 02:36:38 by jlima-so         ###   ########.fr       */
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

void	mark_order(t_table *a)
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
		if (count == 0)
			value->flag = a->max->value * 2 + 3;
		else
			value->flag = value->value + a->max->value + 2;
		ft_printf ("%d\t%d\t%d\n", value->value, count, value->flag); // delete
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
			ft_printf("%d  %d",temp->flag,(int)temp->value);
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

int	check_if_sorted(t_table *a, t_table *b)
{
	t_list	*temp;
	int		flag;

	flag = 0;
	if (b->head != NULL)
		return (1);
	temp = a->head;
	while (temp->next != NULL)
	{
		if (temp->next->value != temp->value + 1 && flag == 1)
			return (1);
		if (temp->next->value != temp->value + 1)
			flag = 1;
		temp = temp->next;
	}
	while (a->head->value != 1 && flag == 1)
		ra(a);
	return (0);
}

int biggest_one(t_table *ta)
{
	t_list	*a;
	t_list	*ret;

	
	ret = ta->min;
	a = ta->head->next;
	while (a)
	{
		if (a->value > ret->value && (a->flag == 0 || a->flag == 1))
			ret = a;
		a = a->next;
	}
	return (ret->value);
}

static t_list	*smallest_flag_and_not_one(t_table *ta)
{
	t_list	*a;
	t_list	*ret;
	int		numb;

	numb = biggest_one(ta);
	ret = ta->max;
	a = ta->head;
	while (a)
	{
		if (a->flag <= ret->flag && a->flag != 0 && a->flag != 1 && ret->value > numb && a->value < ret->value)
			ret = a;
		a = a->next;
	}
	if (ret->flag - (ta->max->value * 2) != 0)
		ret->flag = 1;
	ft_printf("\n we found %d and smallest one is %d\n", ret->value, numb);
	return (ret);
}

void	get_order(t_table *a)
{
	t_list	*comp;
	t_list	*hold;
	int		loops;
	int		count;

	count = 0;
	while (++count <= a->max->value)
	{
		loops = 0;
		comp = a->min;
		a->min->flag = 1;
		hold = smallest_flag_and_not_one(a);
		while (loops < 2 && comp != a->min)
		{
			if (comp == NULL)
			{
				comp = a->head;
				loops++;
			}
			if ((comp->flag != 0 && comp->flag != 1) && comp->flag <= hold->flag && comp->value < hold->value)
				hold = comp;
			comp = comp->next;
			ft_printf ("\nthe next best hold is %d", hold->value);
			ft_printf ("\nvalues are %d and %d, %d", loops, comp->value, a->min->value);
		}
	}
}

int	main(int ac, char **av)
{
	t_table	*a;
	t_table	*b;

	if (ac < 2)
		return (0);
	a = init_table(malloc(sizeof(t_table)));
	if (a == NULL)
		return (printf("Memory Error"));
	b = init_table(malloc(sizeof(t_table)));
	if (b == NULL)
		return (printf("Memory Error"));
	if (ft_init_stack(++av, a))
		return (free (a), printf("ulala"));
	format_stack(a);
	print_value(a, b);
	mark_order (a);
	get_order (a);
	// while (check_if_sorted(a, b))
		// ft_sort_stack(a, b);
	print_value(a, b);
	ft_lstclear(&a->head);
	free (a);
}

// int *var(void)
// {
	// static int a;
// 
	// return (&a);
// }