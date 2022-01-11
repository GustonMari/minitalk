/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:38:41 by gmary             #+#    #+#             */
/*   Updated: 2021/11/29 16:40:00 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero(void)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_zero());
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	while (i < start && s[i])
		i++;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (j < len && s[i])
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
