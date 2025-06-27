/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:06:48 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/16 19:12:21 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CHECKER_H
# define LIBFT_CHECKER_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_putchar(char c);
int			ft_putnbr(int nb);
int			ft_putstr(char *str);
int			ft_put_unsnbr(unsigned int nb);
int			ft_printf(const char *str, ...);
int			ft_putptr(unsigned long int nbr, char *base);
int			ft_putn_base(unsigned int nbr, char *base);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstclear(t_list **lst);
void		ft_lstiter(t_list *lst, int (*f)(long));
t_list		*ft_lstnew(char *content, t_list *last);
char		*skip_spaces(char *str);
void		update_value(t_table *a, t_list *temp);
t_table		*init_table(t_table *a);
int			ft_check(char *str);
char		**ft_split(char const *s, char c);
long		ft_atol(char *str);
int			*ft_sort_array(int ac, int *av);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_str_count(char *str, char c);
void		*free_all(char **strs, int count);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		pa(t_table *b, t_table *a);
void		pb(t_table *a, t_table *b);
void		sa(t_table *a);
void		sb(t_table *a);
void		ra(t_table *a);
void		rb(t_table *a);
void		rr(t_table *a, t_table *b);
void		rra(t_table *a);
void		rrb(t_table *a);
void		rrr(t_table *a, t_table *b);
int			ft_init_stack(char **av, t_table *a);
void		format_stack(t_table *a);
int			check_if_sorted(t_table *a, t_table *b);
void		ft_sort_stack(t_table *a, t_table *b);
void		print_value(t_table *a, t_table *b);
void		push_to_b(t_table *a, t_table *b, int max, int min);
void		organize_to_b(t_table *a, t_table *b);
int			find_closeste(t_table *tb, int skip);
void		push_to_a(t_table *a, t_table *b, int location);

#endif