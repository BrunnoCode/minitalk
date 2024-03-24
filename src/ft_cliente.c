/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cliente.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:44 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/24 12:52:08 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	ft_kill(int pid, char *str)
{
	int				i;
	int				bits;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		bits = 8;
		c = str[i];
		while (bits--)
		{
			if (c >> bits & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("\033[91mError: Try to use \033[0m");
		ft_printf("\033[33m./client <PID SERVER> <STRING>.\033[0m\n");
		exit(1);
	}
	ft_kill(ft_atoi(av[1]), av[2]);
	return (0);
}
