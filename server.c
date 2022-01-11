/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:16:25 by gmary             #+#    #+#             */
/*   Updated: 2022/01/11 15:53:38 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "client.h"

//SIGUSER1 = 1 SIGUSER2 = 0
void	ft_putstr_fd_modif(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	free(s);
}

char	*ft_strjoin_modif(char *s1, char s2)
{
	char	*dest;
	int		i;

	i = 0;
	//if (!s1 || !s2)
	//	return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1 + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = s2;
	i++;
	dest[i] = '\0';
	free(s1);
	return (dest);
}

void	ft_sig_handler(int	sig, siginfo_t *details, void *nothing)
{
	static char	current;
	static int	bits = 7;
	static char	*str;

	(void)details;
	(void)nothing;
	if (sig == SIGUSR1)
		current |= (1 << bits);
	if (sig == SIGUSR2)
		current &= ~(1 << bits);
	bits--;
	if (bits == -1)
	{
		str = ft_strjoin_modif(str, current);
		bits = 7;
		if (current == '\0')
		{
			ft_putstr_fd_modif(str, 1);
			str = NULL;
			current = 0;
			//free(str);
		}
	}
}
/* 
Si SA_SIGINFO est indiqué dans sa_flags, sa_sigaction (plutôt que sa_handler)
indique la fonction gestionnaire de signaux pour signum.
 Cette fonction prend le numéro du signal comme premier argument,
 un pointeur sur un siginfo_t comme second argument 
et un pointeur sur un ucontext_t (transtypé en void *) comme troisième argument.

action.sa_handler = ft_sig_handler;

ou 

 */

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	//action.sa_handler = ft_sig_handler;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	action.sa_sigaction = ft_sig_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	while (1)
		pause();
	return (0);
}