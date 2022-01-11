/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:30:06 by gmary             #+#    #+#             */
/*   Updated: 2021/11/26 09:57:31 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static int	ft_lennum(int n)
{
	int		count;
	long	nbr;

	nbr = (long)n;
	count = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static char	*ft_strrev(char *str, int n)
{
	char	*rev;
	int		i;
	int		j;

	j = ft_lennum(n) - 1;
	i = 0;
	rev = malloc(sizeof(char) * (ft_lennum(n) + 1));
	if (!rev)
		return (NULL);
	while (str[i])
	{
		rev[i] = str[j];
		i++;
		j--;
	}
	rev[i] = '\0';
	return (rev);
}

static char	*ft_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_conv(char *str, long nbr, int i, int n)
{
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	if (n < 0)
	{
		str[i] = '-';
		str[i + 1] = '\0';
	}
	else
		str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		i;

	i = 0;
	nbr = (long)n;
	str = malloc(sizeof(char) * (ft_lennum(n) + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
		return (ft_zero(str));
	if (nbr < 0)
		nbr *= -1;
	return (ft_strrev(ft_conv(str, nbr, i, n), n));
}
