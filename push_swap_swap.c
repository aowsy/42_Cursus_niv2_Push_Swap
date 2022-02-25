/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:14:01 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/16 10:30:04 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_start *start)
{
	t_list	tmp;

	tmp.next = start -> point_b -> next;
	start -> point_b -> next = start -> point_b -> next -> next;
	tmp.next -> next = start -> point_b;
	start -> point_b = tmp.next;
	ft_putstr("sb\n");
	return ;
}

void	ft_sa(t_start *start)
{
	t_list	tmp;

	tmp.next = start -> point_a -> next;
	start -> point_a -> next = start -> point_a -> next -> next;
	tmp.next -> next = start -> point_a;
	start -> point_a = tmp.next;
	ft_putstr("sa\n");
	return ;
}

void	ft_sr(t_start *start)
{
	t_list	tmp;

	tmp.next = start -> point_a -> next;
	start -> point_a -> next = start -> point_a -> next -> next;
	tmp.next -> next = start -> point_a;
	start -> point_a = tmp.next;
	tmp.next = start -> point_b -> next;
	start -> point_b -> next = start -> point_b -> next -> next;
	tmp.next -> next = start -> point_b;
	start -> point_b = tmp.next;
	ft_putstr("ss\n");
	return ;
}
