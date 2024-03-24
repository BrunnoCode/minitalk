/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:33:51 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/24 17:07:06 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ignore(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

static int	isnegative(const char *str, int i)
{
	int	signal;

	signal = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i] == '-')
			signal = -1;
	return (signal);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	num;

	i = ignore(str);
	num = 0;
	signal = isnegative(str, i);
	if (!*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (str[i] >= 48 && str[i] <= 57)
			num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)signal * num);
}
