/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:06:48 by jlima-so          #+#    #+#             */
/*   Updated: 2025/06/03 00:56:28 by jlima-so         ###   ########.fr       */
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

typedef struct s_find
{
	long	curr_favor;
	int		temp_favor;
	int		op;
	int		rt;
}	t_find;

typedef struct s_range
{
	int min;
	int max;
	int delta;
}	t_range;

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*previous;
	long int		value;
	int				flag;
	int				path;
}				t_list;

typedef struct s_table
{
	t_list	*max; // dont need this
	t_list	*min; // dont need this
	t_list	*head;
	t_list	*tail;
	int		size;
}				t_table;

typedef struct s_numb
{
	int	len;
	int	temp;
}			t_numb;

typedef struct s_organize
{
	t_list	*node_to_move;
	t_list	*target_max;
	t_list	*target;
	int		flag;
	int		target_ops;
	int		target_max_ops;
	int		node_to_move_ops;
} t_organize;

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
void	ft_lstiter(t_list *lst, int (*f)(long));
t_list	*ft_lstnew(char *content, t_list *last);
// auxiliar functions
char	*skip_spaces(char *str);
t_table	*init_table(t_table *a);
int		ft_check(char *str);
char	**ft_split(char const *s, char c);
long	ft_atol(char *str);
int		*ft_sort_array(int ac, int *av);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_str_count(char *str, char c);
void	*free_all(char **strs, int count);
void	*ft_memcpy(void *dest, const void *src, size_t n);
// instructions
void	pa(t_table *b, t_table *a);
void	pb(t_table *a, t_table *b);
void	sa(t_table *a);
void	sb(t_table *a);
void	ra(t_table *a);
void	rb(t_table *a);
void	rr(t_table *a, t_table *b);
void	rra(t_table *a);
void	rrb(t_table *a);
void	rrr(t_table *a, t_table *b);

// parsing functions
int		ft_init_stack(char **av, t_table *a);
void	format_stack(t_table *a);
// sorting function
int		check_if_sorted(t_table *a, t_table *b);
void	ft_sort_stack(t_table *a, t_table *b);
// DELETE
void		print_value (t_table *a, t_table *b);
t_organize	find_target(t_list *a, t_list *b, t_list *min);

#endif