/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/03 19:15:13 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

//static char		*str = NULL;
t_str str;

static void ft_mem_alloc()
{
	if (!str.s && str.len)
	{
		str.s = malloc(sizeof(char) * (str.len + 1));
		str.s[str.len] = '\0';
		if (str.s)
		//	printf("\nMALLOC DONE !!!  adress -> %p\n", str.s); // debugging
		str.flag = 1;
	}
}

static void	ft_addstr(int sig)
{
	/*static unsigned char byte = 0;
	static int bits = 8;*/
	static int i = 0;
	if ((sig == SIGUSR1 || sig == SIGUSR2) && str.flag == 1 && str.bits > 0)
	{
		if(sig == SIGUSR1)
			str.byte |= (1 << str.bits);
		--str.bits;
	}
 // printf("\nfunciona bits ? %d\n", str.bits); // debugguing
	if (str.bits == 0 && str.flag == 1)
	{
  //	printf("consegui un caracter %c\n", str.byte); // debugguing
		str.s[i] = str.byte;
  	//printf("\nposicion de str[i] -> %d caracter añadido en str[i] = %c\n", i, str.s[i]); // debugguing
		++i;
		str.byte = 0;
		str.bits = 8;
	}
	if (str.s[i] == '\0')
	{
		ft_putstr(str.s);
		i = 0;
		str.flag = 0;
	}
 // printf("valor de flag %d\n", str.flag); // debugguing
}

static void ft_struct_reset(void)
{
	str.bitlen = 0;
	str.bits = 8;
	if (str.s)
	{
		free(str.s);
		str.s = NULL;
	}
	else
		str.s = NULL;
	str.len = 0;
	str.flag = 0;
}

void	handler_sig(int sig)
{
  /*static int flag = 0;
	static int	bits = 0;
	static int length = 0;*/

	if (str.flag == 0 && str.bitlen <= 31)
	{
		if (sig == SIGUSR1 && str.flag == 0)
			str.len |= (1 << str.bitlen);
		str.bitlen++;
	}
	if (str.bitlen == 32)
	{
		ft_mem_alloc();
		if (!str.s)
			error_control();
		if ((sig == SIGUSR1 || sig == SIGUSR2) && str.flag == 1)
			ft_addstr(sig);
		if (str.flag == 0)
			ft_struct_reset();
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
