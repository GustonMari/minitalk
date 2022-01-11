/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:44:55 by gmary             #+#    #+#             */
/*   Updated: 2021/11/29 14:54:15 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charisset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_cut(int begin, int end, char *trim, char const *s1)
{
	int		i;

	i = 0;
	if (begin < end)
	{
		while (begin < end)
			trim[i++] = s1[begin++];
	}
	trim[i] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		begin;
	int		end;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && ft_charisset(s1[begin], set))
		begin++;
	while (s1[end - 1] && ft_charisset(s1[end - 1], set))
		end--;
	if (end < begin)
		begin = end;
	trim = malloc(sizeof(char) * ((end - begin) + 1));
	if (!trim)
		return (NULL);
	return (ft_cut(begin, end, trim, s1));
}
