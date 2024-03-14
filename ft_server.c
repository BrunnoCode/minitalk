/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:38 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/14 13:11:02 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void  handler_sig(int sig)
{
  ft_printf("Hola cheguei!. sinal = %d\n", sig);
}

int main()
{
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
  
  if (signal(SIGUSR1, handler_sig) == SIG_ERR)
  {
      ft_printf("Signal Error!\n");
      exit(1);
  }
  while (1)
  {
    signal(SIGUSR1, handler_sig);
  }
}