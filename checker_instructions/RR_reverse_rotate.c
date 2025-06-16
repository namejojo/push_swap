/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RR_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:12:10 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/04 17:01:30 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	rr(t_table *a, t_table *b)
{
	if (a == NULL || a->head == a->tail)
		return ;
	if (b == NULL || b->head == b->tail)
		return ;
	a->tail->next = a->head;
	a->tail->next->previous = a->tail;
	a->tail = a->tail->next;
	a->head = a->head->next;
	a->head->previous = NULL;
	a->tail->next = NULL;
	b->tail->next = b->head;
	b->tail->next->previous = b->tail;
	b->tail = b->tail->next;
	b->head = b->head->next;
	b->head->previous = NULL;
	b->tail->next = NULL;
}