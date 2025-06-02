/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:27:10 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/08 14:25:57 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, int (*f)(long))
{
	int	ret;
	
	ret = 0;
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		ret += f(lst->value);
		lst = lst->next;
	}
}
