/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_rotatb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:56:13 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/08 19:13:25 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	rb(t_table *a)
{
	if (a == NULL || a->head == a->tail)
		return ;
	a->tail->next = a->head;
	a->tail->next->previous = a->tail;
	a->tail = a->tail->next;
	a->head = a->head->next;
	a->head->previous = NULL;
	a->tail->next = NULL;
	write (1, "RB\n", 3);
}