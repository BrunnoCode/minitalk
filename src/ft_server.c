/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/24 16:02:34 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	handler_sig(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t	spid;

	spid = getpid();
	if (spid == -1)
	{
		ft_printf("\033[91mERROR: fail to get pid process.\033[0m\n");
		exit(1);
	}
	ft_printf("\033[32mServer ready: ok\033[0m\n");
	sleep(1);
	ft_printf("\033[33mServer Information PID:\033[0m %d\n", spid);
	while (1)
	{
		signal(SIGUSR1, handler_sig);
		signal(SIGUSR2, handler_sig);
		pause();
	}
}
