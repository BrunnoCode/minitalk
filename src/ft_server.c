/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/03 15:58:38 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void ft_mem_alloc(char **s, int length, int *flag)
{
	if (!*s && length)
	{
		*s = malloc(sizeof(char) * (length + 1));
		(*flag) = 1;
	}
}

static int	ft_addstr(char **s, int sig, int length, int flag)
{
	static unsigned char byte = 0;
	static int bits = 8;
	static int i = 0;
  printf("\nfunciona bits ? %d\n", bits); // debugguing
	if (sig == SIGUSR1 && flag == 1 && bits >= 0)
		byte |= (1 << bits);
	if (bits-- == 0 && flag == 1)
	{
  	printf("consegui un caracter %c\n", byte); // debugguing
		(*s)[i++] = byte;
  	printf("\nposicion de str[i] -> %d caracter añadido en str[i] = %c\n", i, *s[i]); // debugguing
		byte = 0;
		bits = 8;
	}
	if (i == length)
	{
		(*s)[i] = '\0';
		ft_putstr(*s);
		return (0);
	}
  printf("valor de flag %d\n", flag); // debugguing
	return (1);
}

static int ft_reset(char **s, int *resetbits)
{
	(*resetbits) = 0;
	if (*s)
	{
		free(*s);
		(*s) = NULL;
	}
	return (0);
}

void	handler_sig(int sig)
{
  static int flag = 0;
	static int	bits = 0;
	static int length = 0;
	static char		*str = NULL;

	if (flag == 0 && bits <= 31)
	{
		if (sig == SIGUSR1 && flag == 0)
			length |= (1 << bits);
		bits++;
	}
	if (bits == 32)
	{
	  printf("valor length: %d\n", length); // debugging
		ft_mem_alloc(&str, length, &flag);
		if (!str)
			error_control();
		if ((sig == SIGUSR1 || sig == SIGUSR2) && flag == 1)
			flag = ft_addstr(&str, sig, length, flag);
		if (flag == 0)
			length = ft_reset(&str, &bits);
		printf("valor de len depois da str: %d\n", length); // debugging
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
