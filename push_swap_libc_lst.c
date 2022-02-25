/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_libc_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:35:56 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/14 17:36:30 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		lst = lst -> next;
		size++;
	}
	return (size);
}

t_list	*ft_lstnew(int content)
{
	t_list	*rtn;

	rtn = malloc(sizeof(*rtn));
	if (!rtn)
		return (NULL);
	rtn -> content = content;
	rtn -> index = 0;
	rtn -> next = NULL;
	return (rtn);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

t_list	*ft_lstforelast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new, char **tab, int j)
{
	t_list	*last;

	if (!alst || !new)
	{
		ft_free_tab(tab, j);
		ft_error(*alst);
	}
	if (!*alst)
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		if (!last)
			return ;
		last -> next = new;
	}
	return ;
}
