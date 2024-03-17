/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cliente.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:44 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/17 19:40:18 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		pid_t servpid;
		char *str;
		int len;
		int i;
		servpid = ft_atoi(av[1]);
		//str = av[2];
		//len = ft_strlen(str);
		i = 31;
		while (i >= 0)
		{
			if (((len >> i) & 1) == 1)
				kill(servpid, SIGUSR1);
			else
				kill(servpid, SIGUSR2);
			i--;
		}
	}
	return (0);
}