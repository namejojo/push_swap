/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:47:07 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/13 22:38:55 by jlima-so         ###   ########.fr       */
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
			ft_printf("  %d", (int)temp->value);
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
	// while (check_if_sorted(a, b))
		ft_sort_stack(a, b);
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