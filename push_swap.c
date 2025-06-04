/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:47:07 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/03 21:52:29 by jlima-so         ###   ########.fr       */
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

// static t_list	*smallest_flag_and_not_one(t_table *ta)
// {
// 	t_list	*a;
// 	t_list	*ret;
// 	int		numb;

// 	numb = biggest_one(ta);
// 	ret = ta->max;
// 	a = ta->head;
// 	while (a)
// 	{
// 		if (a->flag <= ret->flag && a->flag != 0 && a->flag != 1 && ret->value > numb && a->value < ret->value)
// 			ret = a;
// 		a = a->next;
// 	}
// 	if (ret->flag - (ta->max->value * 2) != 0)
// 		ret->flag = 1;
// 	ft_printf("\n we found %d and smallest one is %d\n", ret->value, numb);
// 	return (ret);
// }

// smallest 0 bigger than bigger 1

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
	// mark_bigger_count (a);
	// while (++count < a->max->value)
		// get_order (a);
	// get_last_order(a);
	ft_sort_stack(a, b);
	ft_lstclear(&a->head);
	free (a);
}
