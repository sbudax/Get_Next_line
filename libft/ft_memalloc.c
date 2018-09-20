/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:54:49 by sbxaba            #+#    #+#             */
/*   Updated: 2018/06/04 10:26:09 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	s = (char*)malloc(size);
	if (s == NULL)
		return (NULL);
	while (i < size)
	{
		ft_bzero((void*)s, size);
		i++;
	}
	return (s);
}
