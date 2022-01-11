/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:33:50 by gmary             #+#    #+#             */
/*   Updated: 2022/01/11 10:41:24 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
//a tej
#include <stdio.h>

/* ici dans le while cest assez simple on decale, en premiere instance, de 8 bits vers la gauche le chiffre 1 
soit 10000000 que lon compare avec le charactere c et on decale a chaque apl de 1 vers al droite car on decroit,
si un 1 se situe a la meme position dans c et dans le bitwise alors on renvoie 1;
on commence a 7 pour avoir 8 bits inclue et donc on utilise >= 0 */

void	ft_convert_char(pid_t pid, char c)
{
	int	char_bits;

	char_bits = 7;
	while(char_bits >= 0)
	{
		if (c & (1 << char_bits))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		char_bits--;
	}
}

void	ft_str_convert(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_convert_char(pid, str[i]);
		i++;
	}
	ft_convert_char(pid, '\0');
	return ;
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	//(void)ac;
	//(void)av;
	t_talk	*tlk = NULL;

	if (!ac || ac != 3 || !ft_check(av[1]))
	{
		write(2, "Invalid argument(s)\n", 20);
		return (-1);
	}
	tlk->pid = ft_atoi(av[1]);
	tlk->msg = av[2];
	ft_str_convert(tlk->pid, tlk->msg);

	// mieux utiliser sigaction que signal
	// donner structure a sigaction
	//boucle jai pas recu
	//signaction => jai recu un signal je le lis et je fais mon programme
	//boucle
	//malloc augmentant jusquau \0, jimprime puis free() , puis passage a lautres message
	//
	return (0);
}