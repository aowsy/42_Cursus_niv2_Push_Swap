/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_libc_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:43:04 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/16 10:40:53 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static unsigned long long	ft_atoi_bis(const char *str, t_list *stack,
	char **tab, unsigned int j)
{
	size_t				i;
	unsigned long long	temp;

	i = 0;
	temp = 0;
	while (ft_isdigit(str[i]))
	{
		temp *= 10;
		temp += str[i] - '0';
		i++;
		if (temp > 2147483648)
		{
			ft_free_tab(tab, j);
			ft_error(stack);
		}
	}
	if (str[i])
	{
		ft_free_tab(tab, j);
		ft_error(stack);
	}
	return (temp);
}

int	ft_atoi(const char *str, t_list *stack, char **tab, unsigned int j)
{
	size_t		i;
	int			neg;
	int			res;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	if ((ft_atoi_bis(&str[i], stack, tab, j) == 2147483648) && neg > 0)
	{
		ft_free_tab(tab, j);
		ft_error(stack);
	}
	res = (int)ft_atoi_bis(&str[i], stack, tab, j) * neg;
	return (res);
}
