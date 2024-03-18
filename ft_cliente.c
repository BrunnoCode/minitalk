/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cliente.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:44 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/18 14:17:43 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		pid_t servpid;
		int i;
		unsigned char c;
		servpid = ft_atoi(av[1]);
		c = av[2][0];
		i = 7;
		while (i >= 0)
		{
			if (((c >> i) & 1) == 1)
				kill(servpid, SIGUSR1);
			else
				kill(servpid, SIGUSR2);
			i--;
			usleep(100);
		}
	}
	return (0);
}