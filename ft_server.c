/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/24 10:51:37 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

 void	handler_sig(int sig)
{
// 	static	char byte = 0;
// 	static int bit = 8;
	
// 	if (sig == SIGUSR1)
// 	{			
	
	if (sig == SIGINT)
	{
		ft_printf("\033[91mFinishing Server...\033[0m\n");
		sleep(1);
		ft_printf("\033[32mServer Finished success!\033[0m\n");
		exit(1);
	}
}
	
int	main(void)
{
	struct sigaction sa;
	sa.sa_handler = handler_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
  
	pid_t spid;
	spid = getpid();
  
	if (spid == -1)
	{
		ft_printf("ERROR: fail to get pid process.\n");
		exit(1);
	}
	ft_printf("\033[32mServer ready: ok\033[0m\n");
 	sleep(1);
	ft_printf("\033[33mServer Information PID:\033[0m %d\n", spid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("\033[91mError: Signal.\033[0m\n");
		exit(1);
	}
	sigaction(SIGINT, &sa, NULL);
	while (1)
		pause();
}