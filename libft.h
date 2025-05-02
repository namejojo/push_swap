/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:06:48 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/02 02:40:33 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_array 
{
	int	ind_s;
	int	ind_b;
	int	*ret;
	int	*ret_cmp;
	int	*ret_temp;
	int	flag;
}	t_array;

typedef struct s_list 
{
	struct s_list	*next;
	struct s_list	*previous;
	int				value;
}				t_list;

typedef struct s_place 
{
	t_list	*first;
	t_list	*last;
}				t_place;

typedef struct s_numb
{
	int	len;
	int	temp;
}			t_numb;

// int		ft_itoa_base(int nbr, char *base);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_put_unsnbr(unsigned int nb);
int		ft_printf(const char *str, ...);
int		ft_putptr(unsigned long int nbr, char *base);
int		ft_putn_base(unsigned int nbr, char *base);

int 	ft_check(char *str);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, int (*f)(int));
t_list	*ft_lstnew(int content);

int		ft_atoi(char *str);
int		*ft_sort_array(int ac, int *av);
int		*ft_format_array(int ac, char **av);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);


#endif