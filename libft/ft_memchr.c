/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:43:05 by gmary             #+#    #+#             */
/*   Updated: 2021/11/29 11:36:07 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;
	char	a;

	i = 0;
	s2 = (char *)s;
	a = (char)c;
	while (i < n)
	{
		if (s2[i] == a)
			return (&s2[i]);
		i++;
	}
	return (0);
}
