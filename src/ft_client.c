/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:43:27 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/08 15:22:51 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	first_len(int pid, int len)
{
	int	bits;

	bits = 0;
	while (bits < 32)
	{
		if ((len >> bits) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits++;
		usleep(100);
	}
}

static void	ft_kill(int pid, int c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((c >> bits) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	char	*s;
	int		spid;

	if (ac == 3)
	{
		spid = ft_atoi(av[1]);
		if (spid < 0)
			error_control(4);
		s = av[2];
		first_len(spid, ft_strlen(s));
		while (av[2] && *s)
		{
			ft_kill(spid, *s);
			s++;
		}
	}
	else
		error_control(5);
	return (0);
}
