/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:43:27 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/26 15:22:22 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	ft_kill(int pid, int c)
{
	int	bits;

	bits = 0;
	while (bits <= 7)
	{
		if ((c >> bits) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bits++;
	}
}

int	main(int ac, char **av)
{
	char	*s;
	int		spid;
	int		finish;

	if (ac != 3)
	{
		ft_printf("\033[91mARGS Error Try to use: \033[0m");
		ft_printf("\033[33m./client <PID SERVER> <STRING>.\033[0m\n");
		exit(1);
	}
	s = av[2];
	spid = ft_atoi(av[1]);
	while (av[2] && *s)
	{
		ft_kill(spid, *s);
		s++;
	}
	finish = 7;
	while (finish-- >= 0)
	{
		kill(spid, SIGUSR2);
		usleep(100);
	}
	return (0);
}
