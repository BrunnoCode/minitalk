/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:20:04 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/09 11:08:31 by bbotelho         ###   ########.fr       */
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
	else if (error == 6)
		ft_printf(ERROR_EMPTY_STR);
	else if (error == 7)
		ft_printf(DIFFERENT_PID);
	exit(EXIT_FAILURE);
}
