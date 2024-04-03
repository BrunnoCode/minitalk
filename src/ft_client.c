/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:43:27 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/03 20:39:14 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int finish_len;

static void	first_len(int pid, int len)
{
	int	bits;
	bits = 0;
	ft_printf("valor len client %d\n", len);
	while (bits < 32)
	{
		if ((len >> bits) & 1)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		bits++;
	}
	finish_len = 1;
	ft_printf("valor de bits %d\n", bits);
}

static void	ft_kill(int pid, int c)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if ((c >> bits) & 1)
			kill(pid, SIGUSR1), write(1, "1", 1); //debugging
		else
			kill(pid, SIGUSR2), write(1, "0", 1); //debugging
		bits--;
 		usleep(300);
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
	while (av[2] && *s && finish_len)
	{
		ft_kill(spid, *s);
		s++;
	}
	finish_len = 0;
	return (0);
}
