/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RRR_double_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:21:16 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 18:55:07 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	rrr(t_table *a, t_table *b)
{
	if (a == NULL || a->head == a->tail)
		return ;
	a->head->previous = a->tail;
	a->tail = a->tail->previous;
	a->head->previous->next = a->head;
	a->head = a->head->previous;
	a->head->previous = NULL;
	a->tail->next = NULL;
	if (b == NULL || b->head == b->tail)
		return ;
	b->head->previous = b->tail;
	b->tail = b->tail->previous;
	b->head->previous->next = b->head;
	b->head = b->head->previous;
	b->head->previous = NULL;
	b->tail->next = NULL;
	write(1, "rrr\n", 4);
}
