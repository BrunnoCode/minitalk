/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:11:39 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/09 10:59:02 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_info(pid_t spid)
{
	if (spid == -1)
		error_control(2);
	ft_printf(SERVER_INFO, spid);
	ft_printf(SERVER_DONE);
}
