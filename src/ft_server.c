/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/04 19:34:28 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

t_str		g_str;

static void	ft_struct_reset(int *i)
{
	 if (*g_str.s != NULL && (*i) == g_str.len)
		free(g_str.s);
	g_str.s = NULL;
	g_str.len = 0;
	g_str.bitlen = 0;
	(*i) = 0;
	g_str.flag = 0;
}

static void	ft_mem_alloc()
{
		g_str.s = malloc(sizeof(char) * (g_str.len + 1));
		g_str.s[g_str.len] = '\0';
	  printf("valor de len allocado-> %d\n", g_str.len); //debugging
	if (g_str.s == NULL)
			error_control();
}


void handler_sigstr(int sig)
{
  static int i = 0;
	  if (g_str.flag == 1)
		{
				if (sig == SIGUSR1)
					g_str.byte |= (1 << g_str.bits);
				g_str.bits++;
				if (g_str.bits == 8)
				{
					g_str.s[i] = g_str.byte;
					g_str.bits = 0;
					g_str.byte = 0;
				}
				if (g_str.s[i] == '\0')
				{
						i = 0;
						while (g_str.s[i])
							write(1, &g_str.s[i++], 1); //printf("  caracter escrito ->  %c\n", g_str.s[(*i)]);//debugging
						write(1, "\n", 1);   
						ft_struct_reset(&i);
				}
		}
}


void handler_siglen(int sig)
{
		if (sig == SIGUSR1 && g_str.flag == 0)
			g_str.len |= (1 << g_str.bitlen);
		g_str.bitlen++;
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
	signal(SIGUSR1, handler_siglen);
	signal(SIGUSR2, handler_siglen);
	signal(SIGUSR1, handler_sigstr);
	signal(SIGUSR2, handler_sigstr);
	while (1)
		pause();
}
