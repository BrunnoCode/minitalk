/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:20:04 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/08 14:43:54 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_control(int error)
{
	if (error == 1)
		ft_printf(ERROR_ARGS);
	else if (error == 2)
		ft_printf(ERROR_PID);
	else if (error == 3)
		ft_printf(ERROR_MALLOC);
	else if (error == 4)
		ft_printf(CLIENT_ARGS_ERROR);
	else if (error == 5)
		ft_printf(CLIENT_ARGS_CONTROL);
	exit(EXIT_FAILURE);
}
