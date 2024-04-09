/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/09 11:12:55 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

t_str		g_str;

static void	ft_struct_reset(void)
{
	if (g_str.s != NULL)
		free(g_str.s);
	g_str.s = NULL;
	g_str.len = 0;
	g_str.bitlen = 0;
	g_str.i = 0;
	g_str.flag = 0;
}

static void	ft_mem_alloc(void)
{
	if (g_str.flag == 1)
	{
		if (g_str.s)
			free(g_str.s);
		g_str.s = malloc(sizeof(char) * (g_str.len + 1));
		if (g_str.s == NULL)
			error_control(3);
		g_str.s[g_str.len] = '\0';
	}
}

void	handler_sigstr(int sig)
{
	if (g_str.flag == 1)
	{
		if (sig == SIGUSR1)
			g_str.byte |= (1 << g_str.bits);
		g_str.bits++;
		if (g_str.bits == 8)
		{
			g_str.s[g_str.i++] = g_str.byte;
			g_str.bits = 0;
			g_str.byte = 0;
		}
		if (g_str.i >= g_str.len)
		{
			g_str.i = 0;
			while (g_str.s[g_str.i] != '\0' && g_str.i < g_str.len)
				write(1, &g_str.s[g_str.i++], 1);
			write(1, "\n", 1);
			ft_struct_reset();
		}
	}
}

void	handler_siglen(int sig)
{
	if (g_str.flag == 0)
	{
		if (sig == SIGUSR1 && g_str.flag == 0)
			g_str.len |= (1 << g_str.bitlen);
		g_str.bitlen++;
		if (g_str.bitlen == 32)
		{
			g_str.flag = 1;
			ft_mem_alloc();
		}
	}
}

int	main(int ac, char **av)
{
	pid_t				spid;
	struct sigaction	sa_usr;

	ft_struct_reset();
	ft_init_struct(&sa_usr);
	if (ac != 1 && av[1])
		error_control(1);
	spid = getpid();
	ft_put_info(spid);
	while (1)
	{
		if (g_str.flag == 0)
		{
			sa_usr.__sigaction_u.__sa_handler = handler_siglen;
			sigaction(SIGUSR1, &sa_usr, 0);
			sigaction(SIGUSR2, &sa_usr, 0);
		}
		else if (g_str.flag == 1)
		{
			sa_usr.__sigaction_u.__sa_handler = handler_sigstr;
			sigaction(SIGUSR1, &sa_usr, 0);
			sigaction(SIGUSR2, &sa_usr, 0);
		}
		pause();
	}
}
