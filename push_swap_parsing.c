/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:20:22 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/19 15:58:38 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_index_zero(t_list *stack, int i, int nb)
{
	if (stack != NULL)
	{
		if (ft_index_zero(stack -> next, i, nb))
		{
			if (stack -> index == i)
				stack -> index = 0;
			return (1);
		}
		if ((stack -> index == 0) && (stack -> content < nb))
			return (1);
	}
	return (0);
}

static void	ft_index_bis(t_list *stack, int i)
{
	if (stack -> index == 0)
	{
		stack -> index = i;
		if (!ft_index_zero(stack, i, stack -> content))
			return ;
	}
	if (stack -> next != NULL)
		ft_index_bis(stack -> next, i);
}

static void	ft_index(t_list *stack)
{
	int	i;

	i = 1;
	while (i <= ft_lstsize(stack))
	{
		ft_index_bis(stack, i);
		i++;
	}
	return ;
}

void	ft_parsing_several(char **av, t_list *stack_a, unsigned int i)
{
	int				nb;
	unsigned int	j;
	char			**tab;

	while (av[i])
	{
		if (!ft_isnot_digitspace(av[i]) || !ft_isonly_space(av[i]))
			ft_error(stack_a);
		tab = ft_split(av[i], ' ');
		if (!tab)
			ft_error(stack_a);
		j = 0;
		while (tab[j])
		{
			nb = ft_atoi(tab[j], stack_a, tab, j);
			ft_lstadd_back(&stack_a, ft_lstnew(nb), tab, j);
			ft_lstcheck(stack_a, nb, tab, j);
			j++;
		}
		ft_free_tab(tab, j);
		i++;
	}
	ft_index(stack_a);
	ft_dispatch(stack_a);
	return ;
}
