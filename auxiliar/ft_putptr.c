/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:52:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/04/30 18:34:50 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strlen(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind])
		ind++;
	return (ind);
}

static int	ft_put_adress(unsigned long int nbr, char *base)
{
	unsigned long int	base_len;
	unsigned long int	len;

	len = 1;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		len += ft_put_adress(nbr / base_len, base);
	nbr = nbr % base_len;
	write (1, &base[nbr], 1);
	return (len);
}

int	ft_putptr(unsigned long int nbr, char *base)
{
	int	len;

	if (nbr == 0)
	{
		len = write(1, "(nil)", 5);
		return (5);
	}
	len = write(1, "0x", 2);
	len += ft_put_adress(nbr, base);
	return (len);
}
