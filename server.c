/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:16:25 by gmary             #+#    #+#             */
/*   Updated: 2022/01/11 11:15:42 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "client.h"

//SIGUSER1 = 1 SIGUSER2 = 0
void	ft_sig_handler(int	sig, siginfo_t *details, void *nothing)
{
	static	char	current;
	static	int		bits = 7;
	static	char	*str;
	(void)details;
	(void)nothing;

	//current = NULL;
	if (sig == SIGUSR1)
		current |= (1 << bits);
	bits--;
	if (bits == 0)
	{
		str = malloc(sizeof(char));
		str[ft_strlen(str)] = current;
		if (current == '\0')
		{
			//ft_print;
			free(str);
		}
		bits = 8;
		current = '\0';
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

	//while (message pas finit)
	//	while (tant que le char est pas finit )
	//		while(tant que jai pas recu de signal)
	while (1)
		pause();
	return (0);
}