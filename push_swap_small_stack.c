/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:35:32 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/19 15:46:42 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_position_highest(t_list *stack)
{
	int	max;
	int	rtn;

	rtn = 1;
	max = ft_lstsize(stack);
	while (stack != NULL)
	{
		if (stack -> index == max)
			break ;
		stack = stack ->next;
		rtn++;
	}
	return (rtn);
}

static void	ft_sort_three_stack(t_start *start, int a, int b, int c)
{
	if (start -> point_a -> index == a
		&& start -> point_a -> next -> index == c)
	{
		ft_rra(start);
		ft_sa(start);
	}
	else if (start -> point_a -> index == b
		&& start -> point_a -> next -> index == a)
		ft_sa(start);
	else if (start -> point_a -> index == b
		&& start -> point_a -> next -> index == c)
		ft_rra(start);
	else if (start -> point_a -> index == c
		&& start -> point_a -> next -> index == a)
		ft_ra(start);
	else if (start -> point_a -> index == c
		&& start -> point_a -> next -> index == b)
	{
		ft_sa(start);
		ft_rra(start);
	}
	return ;
}

static void	ft_sort_five_stack(t_start *start)
{
	while (ft_lstsize(start -> point_a) > 3)
	{
		if ((start -> point_a -> index == 1)
			|| start -> point_a -> index == 2)
			ft_pb(start);
		else
			ft_ra(start);
	}
	ft_sort_three_stack(start, 3, 4, 5);
	if (start -> point_b -> index == 1)
		ft_sb(start);
	ft_pa(start);
	ft_pa(start);
}

void	ft_sort_small_stack(t_start *start)
{
	if (ft_lstsize(start -> point_a) == 3)
		ft_sort_three_stack(start, 1, 2, 3);
	else if (ft_lstsize(start -> point_a) == 4)
	{
		while (start -> point_a -> index != 1)
			ft_ra(start);
		ft_pb(start);
		ft_sort_three_stack(start, 2, 3, 4);
		ft_pa(start);
	}
	else if (ft_lstsize(start -> point_a) == 5)
		ft_sort_five_stack(start);
	ft_success(start -> point_a);
}

void	ft_is_sorted(t_list *stack)
{
	int	nb;

	while (stack -> next != NULL)
	{
		nb = stack -> index;
		stack = stack -> next;
		if (stack -> index < nb)
			return ;
	}
	ft_success(stack);
}
