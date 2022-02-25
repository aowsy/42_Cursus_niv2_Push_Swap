/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:17:07 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/16 10:31:29 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_start *start)
{
	t_list	tmp;

	tmp.next = ft_lstforelast(start -> point_b);
	tmp.next -> next -> next = start -> point_b;
	start -> point_b = tmp.next -> next;
	tmp.next -> next = NULL;
	ft_putstr("rrb\n");
	return ;
}

void	ft_rra(t_start *start)
{
	t_list	tmp;

	tmp.next = ft_lstforelast(start -> point_a);
	tmp.next -> next -> next = start -> point_a;
	start -> point_a = tmp.next -> next;
	tmp.next -> next = NULL;
	ft_putstr("rra\n");
	return ;
}

void	ft_rrr(t_start *start)
{
	t_list	tmp;

	tmp.next = ft_lstforelast(start -> point_a);
	tmp.next -> next -> next = start -> point_a;
	start -> point_a = tmp.next -> next;
	tmp.next -> next = NULL;
	tmp.next = ft_lstforelast(start -> point_b);
	tmp.next -> next -> next = start -> point_b;
	start -> point_b = tmp.next -> next;
	tmp.next -> next = NULL;
	ft_putstr("rrr\n");
	return ;
}
