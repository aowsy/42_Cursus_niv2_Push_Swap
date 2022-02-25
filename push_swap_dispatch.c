/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:34:43 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/16 16:21:40 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_check_index(t_list *stack)
{
	int	rtn;

	rtn = stack -> index;
	while (stack)
	{
		if (stack -> index > rtn)
			rtn = stack -> index;
		stack = stack -> next;
	}
	return (rtn);
}

void	ft_push_stack_b_down(t_start *start)
{
	while (start -> point_b -> index != ft_check_index(start -> point_b))
		ft_rrb(start);
	ft_pa(start);
}

void	ft_push_stack_b_up(t_start *start)
{
	while (start -> point_b -> index != ft_check_index(start -> point_b))
		ft_rb(start);
	ft_pa(start);
}

int	ft_check_upndown(t_list *stack)
{
	int	tmp;
	int	count_i;
	int	count_tmp;

	tmp = 0;
	count_tmp = 0;
	count_i = 1;
	while (stack -> next != NULL)
	{
		tmp = stack -> index;
		if (stack -> index > tmp)
		{
			tmp = stack -> index;
			count_tmp = count_i;
		}
		count_i++;
		stack = stack -> next;
	}
	if (count_tmp <= ft_lstsize(stack) / 2)
		return (0);
	return (1);
}

void	ft_sort_stack_b(t_start *start)
{
	while (ft_lstsize(start -> point_b) > 0)
	{
		if (!ft_check_upndown(start -> point_b))
			ft_push_stack_b_up(start);
		else
			ft_push_stack_b_down(start);
	}
	return ;
}

int	ft_check_between_div(t_list *stack, int count, int div_i)
{
	while (stack)
	{
		if ((stack -> index <= div_i) && (stack -> index > (div_i / count) * (count - 1)))
			return (1);
		stack = stack -> next;
	}
	return (0);
}

int	ft_square_root(int nb)
{
	int rtn;

	rtn = 0;
	while (rtn * rtn < nb)
		rtn++;
	return (rtn);
}

int	ft_check_down_sorted(t_list *stack, int count, int div_i)
{
	int	down;
	int	len;

	down = 1;
	len = ft_lstsize(stack);
	while (stack)
	{
		if (stack -> index == (div_i / count) * (count - 1))
			return (len - down);
		down++;
		stack = stack -> next;
	}
	return (0);
}

int	ft_check_up_sorted(t_list *stack, int count, int div_i)
{
	int	up;

	up = 1;
	while (stack)
	{
		if (stack -> index == (div_i / count) * (count - 1))
			return (up);
		up++;
		stack = stack -> next;
	}
	return (0);
}

void	ft_move_sorted(t_start *start, int count, int div_i, int div_max)
{
	t_list *last;

	if (count == div_max)
		return ;
	if (count != 1)
	{
		last = ft_lstlast(start -> point_a);
		if (ft_check_up_sorted(start -> point_a, count, div_i) <= ft_check_down_sorted(start -> point_a, count, div_i))
		{
			while (last -> index != (div_i / count) * (count - 1))
			{
				ft_ra(start);
				last = ft_lstlast(start -> point_a);
			}
		}
		else
		{
			while (last -> index != (div_i / count) * (count - 1))
			{
				ft_rra(start);
				last = ft_lstlast(start -> point_a);
			}
		}
	}
	return ;
}

int	ft_check_down_div(t_list *stack, int count, int div_i)
{
	int	down;
	int	len;

	down = 1;
	len = ft_lstsize(stack);
	while (stack)
	{
		if ((stack -> index <= div_i) && (stack -> index > (div_i / count) * (count - 1)))
			return (len - down);
		down++;
		stack = stack -> next;
	}
	return (0);
}

int	ft_check_up_div(t_list *stack, int count, int div_i)
{
	int	up;

	up = 1;
	while (stack)
	{
		if ((stack -> index <= div_i) && (stack -> index > (div_i / count) * (count - 1)))
			return (up);
		up++;
		stack = stack -> next;
	}
	return (0);
}

void	ft__upndown_div(t_start *start, int count, int div_i)
{
	if (ft_check_up_div(start -> point_a, count, div_i) <= ft_check_down_div(start -> point_a, count, div_i))
		ft_ra(start);
	else
		ft_rra(start);
	return ;
}

void	ft_sort_big_stack(t_start *start)
{
	int	div_max;
	int	div_i;
	int	count;

	div_max = ft_square_root(ft_lstsize(start -> point_a)) / 2;
	count = 1;
	div_i = count * (ft_lstsize(start -> point_a) / div_max);
	while (count <= div_max + 1)
	{
		while (ft_check_between_div(start -> point_a, count, div_i))
		{
			if ((start -> point_a -> index <= div_i) && (start -> point_a -> index > (div_i / count) * (count - 1)))
				ft_pb(start);
			else
				ft__upndown_div(start, count, div_i);
		}
		ft_move_sorted(start, count, div_i, div_max);
		ft_sort_stack_b(start);
		count++;
		div_i = count * (ft_lstsize(start -> point_a) / div_max);
	}
	while (start -> point_a -> index != 1)
		ft_ra(start);
//	ft_lstprint(start -> point_a);
	exit(EXIT_SUCCESS);
}



/*
void	ft_lstprint(t_list *stack)
{
	while (stack != NULL)
	{
		printf("[%d]%d\n", stack -> content, stack -> index);
		stack = stack -> next;
	}
	if (!stack)
		printf("Null\n\n");
	return ;
}
*/
