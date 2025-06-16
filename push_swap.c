/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:47:07 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 18:38:43 by jlima-so         ###   ########.fr       */
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

// void print_value (t_table *a, t_table *b) // delete
// {
	// t_list	*temp;
	// t_list	*temp2;
	// 
	// temp = a->head;
	// temp2 = b->head;
	// ft_printf("\nA\tB");
	// ft_printf("\n");
	// while (temp != NULL || temp2 != NULL)
	// {
		// if (temp)
		// {
			// ft_printf("%d", (int)temp->value);
			// temp = temp->next;
		// }
		// else
			// ft_printf("   ");
		// ft_printf("\t   ");
		// if (temp2)
		// {
			// ft_printf("%d\n", (int)temp2->value);
			// temp2 = temp2->next;
		// }
		// else
			// ft_printf("\n");
	// }
	// ft_printf("\n");
	// ft_printf("--------------------------------\n");
// }

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
