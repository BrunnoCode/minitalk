/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/04 16:17:39 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

t_str		str;

static void	ft_struct_reset(void)
{
	str.len = 0;
	str.bitlen = 0;
	 if (str.s != NULL)
		free(str.s);
	str.s = NULL;
	str.flag = 0;
	str.i = 0;
	str.bits = 8;
}
static void	ft_mem_alloc(void)
{
	if (str.flag == 1 && !str.s)
	{
		str.s = malloc(sizeof(char) * (str.len + 1));
	  printf("MALLOC DONE  !!! adress -> %p\n", str.s); //debugging
		str.s[str.len] = '\0';
	  printf("valor de len allocado-> %d\n", str.len); //debugging
	}
	if (!str.s)
			error_control();
}

static void ft_addstr(int sig)
{
	if ((sig == SIGUSR1 || sig == SIGUSR2) && str.flag == 1 && str.bits >= 1) // esta funcion estaba dentro deste if ft_addstr(sig);
		{
			 if (sig == SIGUSR1)
					str.byte |= (1 << str.bits);
			str.bits--;
			if (str.bits == 0 && str.flag == 1)
			{
				//printf("caracter montado -> %c  flag %d\n", str.byte, str.flag);//debugging
				str.s[str.i++] = str.byte;
				str.bits = 8;
				str.byte = 0;
			}
		}
}

void	handler_sig(int sig)
{
	
	if (str.flag == 0 &&(sig == SIGUSR1 || sig == SIGUSR2))
	{
		if (sig == SIGUSR1 && str.flag == 0 && str.bitlen <= 31)
			str.len |= (1 << str.bitlen);
		str.bitlen++;
	}
	if (str.bitlen == 32)
	{
		str.flag = 1;
		if (!str.s)
			ft_mem_alloc(); 
		ft_addstr(sig);
		if (str.s[str.i] == '\0')
				{
					  printf("valor de i %d\n valor de len %d\n", str.i, str.len);//debugging
						str.i = 0;
						while (str.s[str.i])
							write(1, &str.s[str.i++], 1);
						write(1, "\n", 1);   
						ft_struct_reset();
					  printf("hay algo en *s ? %s\n", str.s);//debugging
				}
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
	ft_struct_reset();
	while (1)
	{
		signal(SIGUSR1, handler_sig);
		signal(SIGUSR2, handler_sig);
		pause();
	}
}
