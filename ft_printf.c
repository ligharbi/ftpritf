/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:38:25 by ligharbi          #+#    #+#             */
/*   Updated: 2025/01/22 12:46:11 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	divide_printf(const char *s, va_list arg)
{
	char	*str;
	int		ret_total_inputs;

	ret_total_inputs = 0;
	str = NULL;
	if (*(s) == 'd' || *(s) == 'i' )
		return (print_i(va_arg(arg, int)));
	else if (*(s) == 'u')
		return (print_u(va_arg(arg, unsigned int)));
	else if (*(s) == 'c')
	{
		str = treat_c(va_arg(arg, int));
		if (*str == '\0')
			return (free(str), ft_putchar('\0'));
	}
	if (str)
	{
		ret_total_inputs += ft_putstr(str);
		free(str);
		str = NULL;
	}
	return (ret_total_inputs);
}

int	divide_printf_2(const char *s, va_list arg)
{
	char	*str;
	int		ret_total_inputs;

	ret_total_inputs = 0;
	str = NULL;
	if (*s == '%')
		return (ft_putchar('%'));
	else if (*(s) == 's')
		str = treat_s(va_arg(arg, char *));
	else if (*(s) == 'p')
		str = treat_p(va_arg(arg, unsigned long long));
	else if (*(s) == 'x' || *(s) == 'X')
		str = treat_hex(va_arg(arg, unsigned int), *s);
	if (str)
	{
		ret_total_inputs += ft_putstr(str);
		free(str);
		str = NULL;
	}
	return (ret_total_inputs);
}

int	ft_printf(const char *s, ...)
{
	int		ret_total_inputs;
	va_list	arg;

	va_start(arg, s);
	ret_total_inputs = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c' || *s == 'd' || *s == 'i' || *s == 'u')
				ret_total_inputs += divide_printf(s, arg);
			else if (*s == '%' || *s == 's' || *s == 'p' || *s == 'x'
				|| *s == 'X')
				ret_total_inputs += divide_printf_2(s, arg);
			s++;
		}
		else
		{
			ret_total_inputs += ft_putchar(*s);
			s ++;
		}
	}
	va_end(arg);
	return (ret_total_inputs);
}
/*
int	ft_printf(const char *s, ...)
{
	char	*str;
	int		ret_total_inputs;
	va_list	arg;

	va_start(arg, s);
	ret_total_inputs = 0;
	str = NULL;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
			{
				ret_total_inputs += ft_putchar('%');
				s++;
				continue ;
			}
			if (*(s) == 'd' || *(s) == 'i')
				ret_total_inputs += print_i(va_arg(arg, int));
			else if (*(s) == 'u')
				ret_total_inputs += print_u(va_arg(arg, unsigned int));
			else if (*(s) == 'c')
			{
				str = treat_c(va_arg(arg, int));
				if (*str == '\0')
					ret_total_inputs += ft_putchar(*str);
			}
			else if (*(s) == 's')
				str = treat_s(va_arg(arg, char *));
			else if (*(s) == 'p')
				str = treat_p(va_arg(arg, unsigned long long));
			else if (*(s) == 'x' || *(s) == 'X')
				str = treat_hex(va_arg(arg, unsigned int), *s);
			else if (*(s - 1) == '%' && *s == '%')
				str = treat_c('%');
			if (str)
			{
				ret_total_inputs += ft_putstr(str);
				free(str);
				str = NULL;
			}
			s ++;
		}
		else
		{
			ret_total_inputs += ft_putchar(*s);
			s ++;
		}
	}
	va_end(arg);
	return (ret_total_inputs);
}
*/
