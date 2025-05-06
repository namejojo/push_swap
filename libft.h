/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:06:48 by jlima-so          #+#    #+#             */
/*   Updated: 2025/05/06 17:27:45 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_split
{
	char	**ret;
	char	*str;
	int		str_count;
	int		indv;
}				t_split;

typedef struct s_array
{
	// int	ind_s;
	// int	ind_b;
	// int	*ret;
	// int	*ret_cmp;
	// int	*ret_temp;
	// int	flag;
}	t_array;

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*previous;
	int				value;
}				t_list;

typedef struct s_table
{
	int		size;
	t_list	*head;
	t_list	*tail;
}				t_table;

typedef struct s_numb
{
	int	len;
	int	temp;
}			t_numb;

// ft_printf
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_put_unsnbr(unsigned int nb);
int		ft_printf(const char *str, ...);
int		ft_putptr(unsigned long int nbr, char *base);
int		ft_putn_base(unsigned int nbr, char *base);
// ft_lists
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, int (*f)(int));
t_list	*ft_lstnew(char *content, t_list *last);
// auxiliar functions
int		ft_check(char *str);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str);
int		*ft_sort_array(int ac, int *av);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_str_count(char *str, char c);
void	*free_all(char **strs, int count);
void	*ft_memcpy(void *dest, const void *src, size_t n);
// parsing functions
int		ft_format_array(char **av, t_table *a);

#endif