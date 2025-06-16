/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PA_pushA.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:29:59 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 19:10:34 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	pa(t_table *b, t_table *a)
{
	if (a->head == NULL)
		return ;
	if (b->head == NULL)
	{
		b->head = a->head;
		a->head = a->head->next;
		a->head->previous = NULL;
		b->head->next = NULL;
		b->head->previous = NULL;
		b->tail = b->head;
	}
	else
	{
		b->head->previous = a->head;
		a->head = a->head->next;
		if (a->head != NULL)
			a->head->previous = NULL;
		else
			a->tail = NULL;
		b->head->previous->next = b->head;
		b->head = b->head->previous;
	}
	a->size--;
	b->size++;
	write (1, "pa\n", 3);
}
