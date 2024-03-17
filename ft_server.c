/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/14 18:48:58 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	handler_sig(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("SIGUSR1 RECEBIDO\n");
	if (sig == SIGUSR2)
		ft_printf("SIGUSR2\n");
	ft_printf("RECEBIDO sinal: %d\n", sig);
}

int	main(void)
{
	struct sigaction sa;
	sa.__sigaction_u.__sa_handler = handler_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
  
	pid_t spid;
	spid = getpid();
  
	if (spid == -1)
	{
		ft_printf("ERROR: fail to get pid process.\n");
		exit(1);
	}
	ft_printf("Server ready: ok\n");
	sleep(1);
	ft_printf("PID Server Information: %i\n", spid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Signal Error!\n");
		exit(1);
	}
	while (1);
}