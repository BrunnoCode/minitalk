/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:28:23 by bbotelho          #+#    #+#             */
/*   Updated: 2024/03/26 15:49:58 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchr(int c, int *datap)
{
	if (*datap != -1)
	{
		if (write(1, &c, 1) == -1)
			*datap = -1;
		else
			*datap += 1;
	}
}

static void	ft_str(char *str, int *datap)
{
	if (!str)
		ft_str("(null)", datap);
	else
	{
		while (*str)
		{
			ft_putchr(*str, datap);
			str++;
		}
	}
}

static void	ft_number(unsigned long n, int *datap, unsigned long base,
		char *basestr)
{
	if ((int)n < 0 && basestr[10] == '\0')
	{
		ft_putchr('-', datap);
		n = -n;
	}
	if (n >= base)
		ft_number(n / base, datap, base, basestr);
	if (*datap == -1)
		return ;
	ft_putchr(basestr[n % base], datap);
}

static void	ft_formats(const char *formato, va_list ap, int *datap)
{
	if (*formato == '%')
		ft_putchr('%', datap);
	else if (*formato == 'c')
		ft_putchr(va_arg(ap, int), datap);
	else if (*formato == 's')
		return (ft_str(va_arg(ap, char *), datap));
	else if (*formato == 'd' || *formato == 'i')
		ft_number(va_arg(ap, int), datap, 10, "0123456789");
	else if (*formato == 'u')
		ft_number(va_arg(ap, unsigned int), datap, 10, "0123456789u");
	else if (*formato == 'x')
		ft_number(va_arg(ap, unsigned int), datap, 16, "0123456789abcdef");
	else if (*formato == 'X')
		ft_number(va_arg(ap, unsigned int), datap, 16, "0123456789ABCDEF");
	else if (*formato == 'p')
	{
		ft_str("0x", datap);
		ft_number(va_arg(ap, unsigned long), datap, 16, "0123456789abcdef");
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		dataprinted;

	dataprinted = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_formats(++format, ap, &dataprinted);
		}
		else
			ft_putchr(*format, &dataprinted);
		format++;
	}
	va_end(ap);
	return (dataprinted);
}
