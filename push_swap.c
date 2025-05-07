/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:47:07 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/07 17:49:05 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static void	init(int ac, char **av, t_table *a)
{
	t_list	*temp;
	int		*array;
	int		ind;

	a->size = 0;
	ft_init_stack(av, a, NULL);
	ind = 0;
	a->head = ft_lstnew(array[ind], );
	if (a->head == NULL)
		return (free (array));
	temp = a->head;
	while (++ind <= ac - 2)
	{
		temp->next = ft_lstnew(array[ind]);
		if (temp->next == NULL)
			return (free (array), ft_lstclear(&a->head), free (a));
		temp->next->previous = temp;
		temp = temp->next;
	}
	a->tail = temp;
} */

t_table	*init_table(t_table *a)
{
	a->head = NULL;
	a->tail = NULL;
	a->max = -2147483648;
	a->min = 2147483647;
	return (a);
}

static void	ft_lstpass(t_table *a)
{
	t_list	*temp;
	
	temp = a->head;
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		temp->value = temp->value + INT_MAX;
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_table	*a;
	// t_table	*b;
	t_list	*temp; //delete

	if (ac < 2)
		return (0);
	a = malloc(sizeof(t_table));
	if (a == NULL)
		return (ft_printf("Memory Error"));
	if (ft_init_stack(++av, init_table(a)))
		return (free (a), ft_printf("ulala"));
	// if (ft_sort_stack(++av, init(a)))
		// return (free (a), ft_printf("ulala"));

	// checking if correct
	temp = a->head;
	while (temp != NULL)
	{
		printf("index: %d, is the number %ld\n", temp->index, temp->value);
		temp = temp->next;
	}
		
	ft_printf("----------------------\nsize is: %d\n", ft_lstsize(a->head));
	ft_printf("head is: %d\n", (int)(a->head->value));
	ft_printf("tail is: %d\n", (int)(a->tail->value));
	ft_printf("max is: %d\n", (a->max));
	ft_printf("min is: %d\n\n\n\n\n", (a->min));
	
	format_stack(a);
	temp = a->head;
	while (temp != NULL)
	{
		printf("index: %d, is the number %ld\n", temp->index, temp->value);
		temp = temp->next;
	}
		
	ft_printf("----------------------\nsize is: %d\n", ft_lstsize(a->head));
	ft_printf("head is: %d\n", (int)(a->head->value));
	ft_printf("tail is: %d\n", (int)(a->tail->value));
	ft_printf("max is: %d\n", (a->max));
	ft_printf("min is: %d\n\n\n\n\n", (a->min));

	// check done
	ft_lstclear(&a->head);
	free (a);
}
