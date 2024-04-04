/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:43:27 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/04 18:40:27 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	first_len(int pid, int len)
{
	int	bits;
	bits = 0;
	ft_printf("valor len client %d\n", len);
	while (bits < 32)
	{
		if ((len >> bits) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits++;
		usleep(100);
	}
	ft_printf("valor de bits %d\n", bits);
}

static void	ft_kill(int pid, int c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((c >> bits) & 1)
			kill(pid, SIGUSR1); //debugging
		else
			kill(pid, SIGUSR2); //debugging
		bits++;
 		usleep(100);
	}
}

int	main(int ac, char **av)
{
	char	*s;
	int		spid;

	if (ac != 3)
	{
		ft_printf("\033[91mARGS Error Try to use: \033[0m");
		ft_printf("\033[33m./client <PID SERVER> <STRING>.\033[0m\n");
		exit(1);
	}
	s = av[2];
	spid = ft_atoi(av[1]);
	first_len(spid, ft_strlen(s));
	usleep(300);
	while (av[2] && *s)
	{
		ft_kill(spid, *s);
		s++;
	}
	return (0);
}
