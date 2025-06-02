/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:31:48 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/07 17:30:16 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	pf_check(char *c, va_list args)
{
	if (*c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*c == 'p')
		return (ft_putptr(va_arg(args, unsigned long int), "0123456789abcdef"));
	else if (*c == 'd' || *c == 'i')
		return (ft_putnbr(va_arg(args, long)));
	else if (*c == 'u')
		return (ft_put_unsnbr(va_arg(args, unsigned int)));
	else if (*c == 'X')
		return (ft_putn_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*c == 'x')
		return (ft_putn_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_numb	n;

	if (write(1, "", 0) == -1)
		return (-1);
	if (str == NULL)
		return (-1);
	va_start (args, str);
	n.len = 0;
	while (*str != '\0')
	{
		n.temp = n.len;
		if (*str != '%')
			n.len = n.len + ft_putchar(*str);
		else if (*(str++) == '%')
			n.len = n.len + pf_check((char *)str, args);
		if (n.temp > n.len)
			return (-1);
		str++;
	}
	va_end (args);
	return (n.len);
}
