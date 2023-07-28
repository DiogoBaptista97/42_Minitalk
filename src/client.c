/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:35:11 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/16 10:35:12 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

void	enviasig(int pid, unsigned char messa)
{
	int		bit;

	bit = 7;
	while (bit >= 0)
	{
		if (messa & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(200);
		bit--;
	}
}

void	validarg(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("formato: pid seguido da mensagem");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("pid not valid");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (argv[2] == NULL)
	{
		ft_printf("message empty");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	validarg(argc, argv);
	pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
	{
		enviasig(pid, argv[2][i]);
	}
	enviasig(pid, '\0');
	return (0);
}
