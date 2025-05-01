/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:46:55 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/01 23:27:14 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_swap(int *a , int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	*ft_sort_array(int ac, int *av)
{
	int l_ind;
	int r_ind;
	
	l_ind = 0;
	while (l_ind < ac - 2)
	{
		r_ind = l_ind;
		while (++r_ind < ac - 1)
			if (av[l_ind] > av[r_ind])
				ft_swap(&av[l_ind], &av[r_ind]);
		l_ind++;
	}
	return (av);
}

int	*ft_atoi_pointer(int ac, char **av)
{
	int	*ret;
	int ind;

	ret = malloc(sizeof(int) * ac - 2);
	if (ret == NULL)
		return (NULL);
	ind = -1;
	while (av[++ind + 1] != NULL)
	{
		if (ft_check(av[ind + 1]))
			return (free(ret), NULL);
		ret[ind] = ft_atoi(av[ind + 1]);
	}
	return (ret);
}

int *ft_format_array(int ac, char **av)
{
	int	ind_l;
	int	ind_b;
	int	*ret;
	int	*ret_cmp;

	ret = ft_atoi_pointer(ac, av);
	if (ret == NULL)
		return (NULL);
	ret_cmp = ft_atoi_pointer(ac, av);
	if (ret_cmp == NULL)
		return (free (ret), NULL);
	ret_cmp = ft_sort_array(ac, ret_cmp);
	ind_b = -1;
	while (++ind_b < ac - 1)
	{
		ind_l = -1;
		while (++ind_l < ac - 1)
			if (ret[ind_l] == ret_cmp[ind_b])
				ret[ind_l] = ind_b;
	}
	free(ret_cmp);
	return (ret);
}
