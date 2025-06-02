/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:21:27 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/02 03:01:08 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next_node;

	if (lst == NULL || *lst == NULL)
		return ;
	while ((*lst)->next != NULL)
	{
		next_node = (*lst)->next;
		free (*lst);
		*lst = next_node;
	}
	free (*lst);
	*lst = NULL;
}
