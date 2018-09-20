/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 07:23:15 by sbxaba            #+#    #+#             */
/*   Updated: 2018/06/06 14:30:21 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char*)dst;
	s2 = (char*)src;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s1[i] == (char)c)
			return ((void *)s1 + (i + 1));
		i++;
	}
	return (NULL);
}
