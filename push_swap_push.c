/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:51:07 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/16 10:32:24 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_start *start)
{
	t_list	tmp;

	tmp.next = start -> point_a;
	start -> point_a = start -> point_a -> next;
	tmp.next -> next = start -> point_b;
	start -> point_b = tmp.next;
	ft_putstr("pb\n");
	return ;
}

void	ft_pa(t_start *start)
{
	t_list	tmp;

	tmp.next = start -> point_b;
	start -> point_b = start -> point_b -> next;
	tmp.next -> next = start -> point_a;
	start -> point_a = tmp.next;
	ft_putstr("pa\n");
	return ;
}
