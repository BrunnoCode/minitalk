/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:21:44 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/03 17:36:42 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		error_control();
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		error_control();
	i = -1;
	while (++i < len1)
	{
		str[i] = s1[i];
	}
	j = -1;
	while (++j < len2)
	{
		str[j + i] = s2[j];
	}
	str[j + i] = '\0';
	return (str);
}
