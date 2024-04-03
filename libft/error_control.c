/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:20:04 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/03 17:24:05 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_control(void)
{
	ft_printf("\033[91mERROR:\033[0m malloc fail.\n");
	exit(EXIT_FAILURE);
}
