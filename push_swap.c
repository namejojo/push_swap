/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:47:07 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/02 02:38:19 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_radix(int ac, char **av, t_place *a)
{
	t_list	*temp;
	int		*array;
	int		ind;

	array = ft_format_array(ac, av);
	ind = 0;
	a->first = ft_lstnew(array[ind]);
	if (a->first == NULL)
		return (free (array));
	temp = a->first;
	while(++ind <= ac - 2)
	{
		temp->next = ft_lstnew(array[ind]);
		if (temp->next == NULL)
			return (free (array), ft_lstclear(&a->first), free (a));
		temp->next->previous = temp;
		temp = temp->next;
	}
	a->last = temp;
}

static void	init_mech(int ac, char **av, t_place *a)
{
	t_list	*temp;
	int		*array;
	int		ind;

	array = ft_format_array(ac, av);
	ind = 1;
	a->first = ft_lstnew(array[ind]);
	if (a->first == NULL)
		return (free (a));
	temp = a->first;
	while(array[++ind] && ind <= ac - 1)
	{
		temp->next = ft_lstnew(array[ind]);
		if (temp->next == NULL)
			return (ft_lstclear(&a->first), free (a));
		temp->next->previous = temp;
		temp = temp->next;
	}
	a->last = temp;
}

int main(int ac, char **av)
{
	t_place *a;
	// t_place *b;
	
	if (ac < 2)
		return (ft_printf("ERROR"));
	a = malloc(sizeof(t_place));
	if (a == NULL)
		return (ft_printf("Memory Error"));
	if (ac <= 100)
		init_radix(ac, av, a);
	else
		init_mech(ac, av, a);
	if (a->first == NULL)
		return (ft_printf("ERROR"));
	
	ft_lstiter(a->first, ft_putnbr); // printing values
	
	ft_lstclear(&a->first);
	free (a);
}
