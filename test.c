/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:26:26 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/01 19:43:52 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main()
{
  int len = 4;
  int newlen = 0;
  
  int bits = 8;
  int byte = 8;
  
  while (bits && byte)
  {
    if ((len >> byte) & 1)
         newlen |= (1 << bits);
    bits--;
    byte--;
  }
  printf("valor de len = %d  valor de newlen = %d\n", len, newlen);
  return (0);
  
}
