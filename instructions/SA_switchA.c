/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SA_switchA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:29:59 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/31 21:00:36 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	sa(t_table *a)
{
	int	temp;
	
	temp = a->head->value;
	a->head->value = a->head->next->value;
	a->head->next->value = temp;
	write (1, "SA\n", 3);
}
