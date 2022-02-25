/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_libc_lst_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:36:50 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/16 11:57:56 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstcheck(t_list *stack, int nb, char **tab, unsigned int j)
{
	while (stack && (stack -> next) != NULL)
	{
		if (nb == (stack -> content))
		{
			ft_free_tab(tab, j);
			ft_error(stack);
		}
		stack = stack -> next;
	}
	return ;
}

void	ft_lstfree(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack -> next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
	return ;
}
