/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:59:15 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/08 12:52:01 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include "../src/ft_minitalk.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_str
{
	char			*s;
	unsigned char	byte;
	int				bits;
	int				i;
	int				len;
	int				bitlen;
	int				flag;
}					t_str;

int					ft_atoi(const char *str);
int					ft_printf(char const *format, ...);
int					ft_strlen(char *s);
void				ft_putstr(char *s);
void				error_control(int typeoferror);
void				ft_put_info(pid_t spid);

#endif
