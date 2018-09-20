/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:10:30 by sbxaba            #+#    #+#             */
/*   Updated: 2018/06/18 08:25:55 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		l;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	l = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[l] == ' ' || s[l] == '\n' || s[l] == '\t') && (i < l))
		l--;
	l++;
	str = ft_strnew(l - i);
	if (str == 0)
		return (NULL);
	while (i < l)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
