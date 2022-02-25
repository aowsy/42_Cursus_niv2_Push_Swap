/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:56:07 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/16 10:31:53 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_start *start)
{
	t_list	tmp;

	tmp.next = ft_lstlast(start -> point_b);
	tmp.next -> next = start -> point_b;
	start -> point_b = start -> point_b -> next;
	tmp.next -> next -> next = NULL;
	ft_putstr("rb\n");
	return ;
}

void	ft_ra(t_start *start)
{
	t_list	tmp;

	tmp.next = ft_lstlast(start -> point_a);
	tmp.next -> next = start -> point_a;
	start -> point_a = start -> point_a -> next;
	tmp.next -> next -> next = NULL;
	ft_putstr("ra\n");
	return ;
}

void	ft_rr(t_start *start)
{
	t_list	tmp;

	tmp.next = ft_lstlast(start -> point_a);
	tmp.next -> next = start -> point_a;
	start -> point_a = start -> point_a -> next;
	tmp.next -> next -> next = NULL;
	tmp.next = ft_lstlast(start -> point_b);
	tmp.next -> next = start -> point_b;
	start -> point_b = start -> point_b -> next;
	tmp.next -> next -> next = NULL;
	ft_putstr("rr\n");
	return ;
}
