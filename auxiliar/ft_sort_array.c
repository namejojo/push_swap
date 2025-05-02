/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:46:55 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/02 02:45:32 by jlima-so         ###   ########.fr       */
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

static int	*ft_atoi_pointer(int ac, char **av)
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

static void initialize(t_array *data, int ac, char **av)
{
	data->ret = malloc(sizeof(int) * ac - 2);
	if (data->ret == NULL)
		return ;
	data->ret_temp= ft_atoi_pointer(ac, av);
	if (data->ret_temp== NULL)
		return (free(data->ret));
	data->ret_cmp = ft_atoi_pointer(ac, av);
	if (data->ret_cmp == NULL)
		return (free (data->ret), free (data->ret_temp));
	data->ret_cmp = ft_sort_array(ac, data->ret_cmp);
}

int *ft_format_array(int ac, char **av)
{
	t_array data;

	initialize (&data, ac, av);
	data.ind_b = 0;
	while (++data.ind_b < ac - 1)
	{
		data.ind_s = -1;
		while (++data.ind_s < ac - 1)
			if (data.ret_temp[data.ind_s] == data.ret_cmp[data.ind_b]\
					 && data.ret[data.ind_s] == 0)
				data.ret[data.ind_s] = data.ind_b;
	}
	free(data.ret_cmp);
	free(data.ret_temp);
	return (data.ret);
}
