/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RA_rotateA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:11:02 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/05 14:06:08 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ra(t_table *a)
{
	if (a == NULL || a->head == a->tail)
		return ;
	a->tail->next = a->head;
	a->tail->next->previous = a->tail;
	a->tail = a->tail->next;
	a->head = a->head->next;
	a->head->previous = NULL;
	a->tail->next = NULL;
	write (1, "ra\n", 3);
}
