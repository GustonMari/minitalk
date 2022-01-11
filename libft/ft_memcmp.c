/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:45:27 by gmary             #+#    #+#             */
/*   Updated: 2021/11/29 11:02:37 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s3;
	char	*s4;

	s3 = (char *)s1;
	s4 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s3[i] == s4[i] && i < (n - 1))
	{
		i++;
	}
	return ((unsigned char)s3[i] - (unsigned char)s4[i]);
}
