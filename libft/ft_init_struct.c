/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:07:45 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/08 18:24:36 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_struct(struct sigaction *sa_usr)
{
	sigemptyset(&(sa_usr->sa_mask));
	sa_usr->sa_flags = 0;
}

