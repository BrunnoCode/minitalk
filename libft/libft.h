/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:59:15 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/03 19:02:45 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include "../src/ft_minitalk.h"
# include <stdarg.h>

typedef struct s_str
{
	char			*s;
	unsigned char	byte;
	int				len;
	int				bitlen;
	int				bits;
	int				flag;
}					t_str;

int					ft_atoi(const char *str);
int					ft_printf(char const *format, ...);
int					ft_strlen(char *s);
void				ft_putstr(char *s);
void				error_control(void);
char				*ft_strjoin(char *s1, char *s2);

#endif
