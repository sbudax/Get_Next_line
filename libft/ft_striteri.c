/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:06:36 by sbxaba            #+#    #+#             */
/*   Updated: 2018/06/04 10:10:42 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;
	int j;

	i = 0;
	if (s != NULL && *f != NULL)
	{
		j = ft_strlen(s);
		while (i < j)
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}