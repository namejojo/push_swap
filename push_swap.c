/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:47:07 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/06 18:00:03 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static void	init(int ac, char **av, t_table *a)
{
	t_list	*temp;
	int		*array;
	int		ind;

	a->size = 0;
	ft_format_array(av, a, NULL);
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

static t_table	*init(t_table *a)
{
	a->head = NULL;
	a->tail = NULL;
	a->size = -1;
	return (a);
}


int	main(int ac, char **av)
{
	t_table	*a;
	// t_table	*b;

	if (ac < 2)
		return (ft_printf("ERROR"));
	a = malloc(sizeof(t_table));
	if (a == NULL)
		return (ft_printf("Memory Error"));
	if (ft_format_array(++av, init(a)))
		return (free (a), ft_printf("ERROR"));
	if (a->head == NULL)
		return (free (a), ft_printf("ERROR"));
	
	// checking if correct
	ft_lstiter(a->head, ft_putnbr);
	ft_printf("size is: %d\n", ft_lstsize(a->head));
	ft_printf("head is: %d\n", (a->head->value));
	ft_printf("tail is: %d\n", (a->tail->value));
	// check done
	ft_lstclear(&a->head);
	free (a);
}
