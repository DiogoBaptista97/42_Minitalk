/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:34:58 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/16 10:34:59 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

void	ft_msg(int sinal)
{
	static int	pos;
	static int	c;

	if (sinal == SIGUSR1)
	{
		c += 1 << (7 - pos);
	}
	pos++;
	if (pos == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			ft_printf("\n");
		pos = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid:%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_msg);
		signal(SIGUSR2, ft_msg);
		pause ();
	}
	return (0);
}
