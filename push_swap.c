/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:39:22 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/19 15:41:41 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_success(t_list *stack)
{
	ft_lstfree(stack);
	exit(EXIT_SUCCESS);
}

void	ft_error(t_list *stack)
{
	write(2, "Error\n", 6);
	ft_lstfree(stack);
	exit(EXIT_FAILURE);
	return ;
}

void	ft_dispatch(t_list *stack_a)
{
	t_list	*stack_b;
	t_start	start;

	stack_b = NULL;
	start.point_a = stack_a;
	start.point_b = stack_b;
	ft_is_sorted(stack_a);
	if (ft_lstsize(start.point_a) == 2)
	{
		if (start.point_a -> index > start.point_a -> next -> index)
			ft_sa(&start);
		ft_success(start.point_a);
	}
	if (ft_lstsize(stack_a) <= 5)
		ft_sort_small_stack(&start);
	ft_radix(&start);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	else
		ft_parsing_several(av, NULL, 1);
	return (0);
}
