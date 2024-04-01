/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:59:15 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/01 18:29:20 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include "../src/ft_minitalk.h"
# include <stdarg.h>

int		ft_atoi(const char *str);
int		ft_printf(char const *format, ...);
int		ft_strlen(char *s);
void	ft_putstr(char *s);
void	error_control(void);

#endif
