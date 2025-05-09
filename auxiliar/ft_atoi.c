/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:14:12 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/08 11:22:15 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atol(char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	str = skip_spaces(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48) * (sign);
		str++;
	}
	return (num);
}

// int main()
// {
// 	char * str = "  \n\t\v\r2147483648";
// 	printf("Og return %d\n", atoi(str));
// 	printf("My return %d", ft_atoi(str));		

// }
