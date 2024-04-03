/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/03 20:59:39 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

t_str		str;

static void	ft_struct_reset(void)
{
	str.len = 0;
	free(str.s);
	str.s = NULL;
	str.i = 0;
	str.bits = 8;
	str.bitlen = 0;
	str.flag = 0;
}
static void	ft_mem_alloc(void)
{
	printf("valor de len %d\n", str.len); //debugging
	if (!str.s && str.len && str.flag == 1)
	{
		str.s = malloc(sizeof(char) * (str.len + 1));
		if (!str.s)
			error_control();
	  printf("MALLOC DONE  !!! adress -> %p\n", str.s); //debugging
		str.s[str.len] = '\0';
	}
}

void	handler_sig(int sig)
{
	if (str.flag == 0 && str.bitlen <= 31)
	{
		if (sig == SIGUSR1 && str.flag == 0)
			str.len |= (1 << str.bitlen);
		str.bitlen++;
	}
	if (str.bitlen == 32)
	{
		str.flag = 1;
		ft_mem_alloc();
		if ((sig == SIGUSR1 || sig == SIGUSR2) && str.flag == 1) // esta funcion estaba dentro deste if ft_addstr(sig);
		{
			str.byte |= (1 << str.bits);
			str.bits--;
			if (str.bits == 0 && str.flag == 1)
			{
				printf("caracter montado -> %c\n flag %d\n", str.byte, str.flag);//debugging
				str.s[str.i++] = str.byte;
				str.bits = 8;
				str.byte = 0;
			}
			if (str.i == str.len)
			{
				str.i = 0;
				while (str.s[str.i] != '\0')
					write(1, &str.s[str.i++], 1);    
				ft_struct_reset();
			}
		}
	}
}

int	main(int ac, char **av)
{
	pid_t	spid;

	ft_struct_reset();
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
