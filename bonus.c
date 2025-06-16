/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:13:22 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/04 17:01:07 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_checker.h"
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line_bonus.h"

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

static void execute(char *s, t_table *a, t_table *b)
{
	if (ft_strncmp(s, "PA\n", 3) == 0)
		return (pa(a, b));
	if (ft_strncmp(s, "PB\n", 3) == 0)
		return (pb(a, b));
	if (ft_strncmp(s, "SA\n", 3) == 0)
		return (sa(a));
	if (ft_strncmp(s, "SB\n", 3) == 0)
		return (sb(b));
	if (ft_strncmp(s, "RA\n", 3) == 0)
		return (ra(a));
	if (ft_strncmp(s, "RB\n", 3) == 0)
		return (rb(b));
	if (ft_strncmp(s, "RRA\n", 4) == 0)
		return (rra(a));
	if (ft_strncmp(s, "RRB\n", 4) == 0)
		return (rrb(b));
	if (ft_strncmp(s, "RR\n", 3) == 0)
		return (rr(a, b));
	if (ft_strncmp(s, "RRR\n", 4) == 0)
		return (rrr(a, b));
}

static void	ft_checker(t_table *a, t_table *b)
{
	t_list	*la;

	if (b->head != NULL)
		write (1, "KO\n", 3);
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

int	main(int ac, char **av)
{
	t_table	*a;
	t_table	*b;
	char	*cmd;

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
	cmd = get_next_line(0);
	while (cmd)
	{
		execute(cmd , a, b);
		free (cmd);
		cmd = get_next_line(0);
	}
	ft_checker(a, b);
	ft_lstclear(&a->head);
	free (a);
}