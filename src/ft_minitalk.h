/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:21:33 by bbotelho          #+#    #+#             */
/*   Updated: 2024/04/08 15:15:33 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_PID "\033[91mERROR: fail to get pid process.\033[0m\n"
# define ERROR_ARGS "\033[91mError! type only:\033[0m ./server\n"
# define ERROR_MALLOC "\033[91mERROR:\033[0m malloc fail.\n"
# define SERVER_INFO "\033[33mServer Information PID:\033[0m %d\n"
# define SERVER_DONE "\033[32mServer waiting for signals...\033[0m\n"
# define CLIENT_ARGS_ERROR "\033[91mERROR: The PID must be greater than 0.\033[0m\n"
# define CLIENT_ARGS_CONTROL "\033[33mERROR: Try ./client <PID SERVER> <STRING>.\033[0m\n"

#endif