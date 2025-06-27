/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:13:22 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 18:51:30 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line_bonus.h"
#include "libft.h"
#include "libft_checker.h"

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

static void	execute(char *s, t_table *a, t_table *b)
{
	if (ft_strncmp(s, "pa\n", 3) == 0)
		return (pa(a, b));
	if (ft_strncmp(s, "pb\n", 3) == 0)
		return (pb(a, b));
	if (ft_strncmp(s, "sa\n", 3) == 0)
		return (sa(a));
	if (ft_strncmp(s, "sb\n", 3) == 0)
		return (sb(b));
	if (ft_strncmp(s, "ra\n", 3) == 0)
		return (ra(a));
	if (ft_strncmp(s, "rb\n", 3) == 0)
		return (rb(b));
	if (ft_strncmp(s, "rra\n", 4) == 0)
		return (rra(a));
	if (ft_strncmp(s, "rrb\n", 4) == 0)
		return (rrb(b));
	if (ft_strncmp(s, "rr\n", 3) == 0)
		return (rr(a, b));
	if (ft_strncmp(s, "rrr\n", 4) == 0)
		return (rrr(a, b));
}

static void	ft_checker(t_table *a, t_table *b)
{
	t_list	*la;

	if (b->head != NULL)
	{
		write (1, "KO\n", 3);
		return ;
	}
	la = a->head->next;
	while (la)
	{
		if (la->previous->value > la->value)
		{
			write (1, "KO\n", 3);
			return ;
		}
		la = la->next;
	}
	write (1, "OK\n", 3);
}

void	bonus_part(t_table *a, t_table *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		execute(cmd, a, b);
		free (cmd);
		cmd = get_next_line(0);
	}
	ft_checker(a, b);
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
		return (free (a), write(2, "Error\n", 7));
	if (ft_init_stack(++av, a))
		return (ft_lstclear(&a->head), free (a), free (b), \
	write(2, "Error\n", 7));
	format_stack(a);
	bonus_part(a, b);
	ft_lstclear(&a->head);
	free (a);
	free (b);
}
