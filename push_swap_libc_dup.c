/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_libc_dup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:36:47 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/19 15:48:04 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab(char **tab, size_t i)
{
	i++;
	while (i)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return ;
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		str = malloc(sizeof(*str) * (ft_strlen(s) + 1));
	else
		str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while ((i + start < ft_strlen(s)) && (i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (&str[0]);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || i == ft_strlen(s) || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	ft_split_str(char const *s, char c, char **tab, size_t i)
{
	size_t	j;
	size_t	word_len;

	j = 0;
	while (i < ft_count_word(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		word_len = 0;
		while (s[j] && s[j] != c)
		{
			word_len++;
			j++;
		}
		tab[i] = ft_substr(&s[0], j - word_len, word_len);
		if (!tab[i])
		{
			ft_free_tab(tab, i);
			return ;
		}
		i++;
	}
	tab[i] = 0;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (ft_count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	ft_split_str(s, c, tab, 0);
	j = 0;
	while (tab[j])
		j++;
	i = 0;
	while (tab[i])
	{
		if ((tab[i][0] == '-' || tab[i][0] == '+') && tab[i][1] == '\0')
		{
			ft_free_tab(tab, j);
			return (NULL);
		}
		i++;
	}
	return (tab);
}
