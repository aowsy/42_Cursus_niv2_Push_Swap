/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:03:30 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/16 13:03:14 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_tmp_sorted(t_start start)
{
	int	i;
	int	nb;
	int	size;

	if (ft_lstsize(start.point_b))
		return (1);
	size = ft_lstsize(start.point_a);
	i = 1;
	while (i < size)
	{
		nb = start.point_a -> index;
		start.point_a = start.point_a -> next;
		if ((start.point_a -> index) < nb)
			return (1);
		i++;
	}
	return (0);
}

void	ft_radix(t_start *start)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_lstsize(start -> point_a);
	while (ft_tmp_sorted(*start))
	{
		j = 0;
		while (j < size)
		{
			if (((start -> point_a -> index) >> i) & 1)
				ft_ra(start);
			else
				ft_pb(start);
			j++;
		}
		while (ft_lstsize(start -> point_b))
			ft_pa(start);
		i++;
	}
	ft_success(start -> point_a);
}
