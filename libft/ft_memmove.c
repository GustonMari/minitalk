/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:50:57 by gmary             #+#    #+#             */
/*   Updated: 2021/11/26 14:44:39 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*cp_dst;
	char	*cp_src;

	if (!dest && !src)
		return (NULL);
	cp_dst = (char *)dest;
	cp_src = (char *)src;
	if (dest > src)
	{
		while (len > 0)
		{
			cp_dst[len - 1] = cp_src[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
