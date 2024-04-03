/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:26:26 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/03 17:36:25 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
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

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "hello";
	s2 = "World";
	printf("Resultado: '%s'\n memoria s1: '%p' \n memoria s2 '%p' \n", ft_strjoin(s1, s2), s1, s2);
	return (0);
}
