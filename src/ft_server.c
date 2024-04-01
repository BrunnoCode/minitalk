/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/01 21:21:21 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static int	flag = 0;
static int	len = 0;

static void	ft_addstr(char **s, int sig, int length)
{
	static unsigned char byte = 0;
	static int bits = 7;
	static int i = 0;
  printf("valor de len %d\n", length); // debugguing
	if (sig == SIGUSR1 && flag == 1)
		byte |= (1 << bits);
	bits--;
	if (bits <= 0 && flag == 1)
	{
		(*s)[i++] = byte;
		byte = 0;
		bits = 7;
	}
	if (i == length)
	{
		(*s)[i] = '\0';
		ft_putstr(*s);
		i = 0;
		flag = 0;
		len = 0;
		free(*s);
	}
}
void	handler_sig(int sig)
{
	static int	bits = 32;
	int length;
	char		*str;

	if (sig == SIGUSR1 && flag == 0 && bits > 0)
			len |= (1 << bits);
	bits--;
	if (bits == 0 && len != 0)
	{
	  printf("valor len: %d\n", len); // debugging
		length = len;
		flag = 1;
		str = malloc(sizeof(char) * (length + 1));
		if (!str)
			error_control();
		bits = 0;
		if (sig == SIGUSR1 || sig == SIGUSR2)
			ft_addstr(&str, sig, length);
		printf("valor de len depois da str: %d\n", len); // debugging
	}
}

int	main(int ac, char **av)
{
	pid_t	spid;

	if (ac != 1 && av[1])
	{
		ft_printf("\033[91mError! type only:\033[0m ./server\n");
		exit(EXIT_FAILURE);
	}
	spid = getpid();
	if (spid == -1)
	{
		ft_printf("\033[91mERROR: fail to get pid process.\033[0m\n");
		exit(1);
	}
	ft_printf("\033[33mServer Information PID:\033[0m %d\n", spid);
	sleep(1);
	ft_printf("\033[32mServer waiting for signals...\033[0m\n");
	signal(SIGUSR1, handler_sig);
	signal(SIGUSR2, handler_sig);
	while (1)
		pause();
}
