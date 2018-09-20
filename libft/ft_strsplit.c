/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:04:23 by sbxaba            #+#    #+#             */
/*   Updated: 2018/06/15 11:16:47 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrdc(const char *s, char c)
{
	int i;
	int co;

	i = 0;
	co = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			co++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (co);
}

static	int	ft_wrdl(const char *s, char c)
{
	int i;
	int l;

	i = 0;
	l = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c)
	{
		l++;
		i++;
	}
	return (l);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	str = (char**)malloc(sizeof(char*) * (ft_wrdc(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (i < ft_wrdc(s, c))
	{
		j = 0;
		str[i] = ft_strnew(ft_wrdl(&s[k], c));
		while (s[k] != '\0' && s[k] == c)
			k++;
		while (s[k] != '\0' && s[k] != c)
			str[i][j++] = s[k++];
		i++;
	}
	str[i] = NULL;
	return (str);
}
