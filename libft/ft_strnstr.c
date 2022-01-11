/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:48:58 by gmary             #+#    #+#             */
/*   Updated: 2021/11/29 12:06:54 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t		i;
	size_t		j;
	char		*s1;
	char		*to_find;

	i = 0;
	s1 = (char *)s;
	to_find = (char *)find;
	if (!*find)
		return ((char *)s);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i + j] == to_find[j])
		{
			while (s1[i + j] && s1[i + j] == to_find[j] && (i + j) < len)
				j++;
			if (!to_find[j])
				return (&s1[i]);
		}
		i++;
	}
	return (0);
}
