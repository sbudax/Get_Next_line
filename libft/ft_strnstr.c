/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:09:33 by sbxaba            #+#    #+#             */
/*   Updated: 2018/06/12 16:03:27 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i <= n)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j <= n)
		{
			if (needle[j + 1] == '\0')
				return ((char*)haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
