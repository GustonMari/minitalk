/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:04:31 by gmary             #+#    #+#             */
/*   Updated: 2022/01/11 11:14:52 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct	s_talk
{
	int		pid;
	char	*msg;
}				t_talk;


#endif