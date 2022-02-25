/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:49:35 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/19 15:30:20 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_start
{
	struct s_list	*point_a;
	struct s_list	*point_b;
}				t_start;

//	Push_swap
void	ft_dispatch(t_list *stack_a);
void	ft_sort_small_stack(t_start *start);
int		ft_position_highest(t_list *stack);
void	ft_is_sorted(t_list *stack);
void	ft_parsing_several(char **av, t_list *stack_a, unsigned int i);
void	ft_radix(t_start *start);

//	Operations
void	ft_sa(t_start *start);
void	ft_sb(t_start *start);
void	ft_sr(t_start *start);
void	ft_ra(t_start *start);
void	ft_rb(t_start *start);
void	ft_rr(t_start *start);
void	ft_rra(t_start *start);
void	ft_rrb(t_start *start);
void	ft_rrr(t_start *start);
void	ft_pa(t_start *start);
void	ft_pb(t_start *start);

//	Libc
size_t	ft_strlen(const char *s);
void	ft_putstr(char *str);
int		ft_atoi(const char *str, t_list *stack, char **tab, unsigned int j);
char	**ft_split(char const *s, char c);
int		ft_isnot_digitspace(char *str);
char	*ft_strchr(const char *s, int c);
void	ft_free_tab(char **tab, size_t i);
void	ft_error(t_list *stack);
void	ft_success(t_list *stack);
int	ft_isonly_space(char *str);

//	Lst
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstforelast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new, char **tab, int j);
void	ft_lstcheck(t_list *stack, int nb, char **tab, unsigned int j);
void	ft_lstfree(t_list *stack);

#endif
