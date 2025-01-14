/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:52:06 by ligharbi          #+#    #+#             */
/*   Updated: 2025/01/13 09:52:55 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf (const char *s, ...)
{
	char	*str;
	int		ret_total_inputs;
	va_list	arg;

	va_start(arg, s);
	ret_total_inputs = 0;
	str = NULL;
	while (*s != '\0')
	{
		if(*s == '%')
		{
			s++;
			while (is_ident(*(s)) == 1)
			{
				if(is_ident(*(s -1)) == 0)
					ret_total_inputs += ft_putchar(*s);
				if (*(s) == 'd' || *(s) == 'i')
					ret_total_inputs += print_i(va_arg(arg, int));
				else if (*(s) == 'u')
					ret_total_inputs += print_u(va_arg(arg, unsigned int));
				else if (*(s) == 'c')
				{
					str = treat_c(va_arg(arg, int));
					if(*str == '\0')
					{
						ret_total_inputs += ft_putchar(*str);
					}
				}
				else if (*(s - 1) == '%' && *s == '%')
					str = treat_c('%');
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
				s++;
			}
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

// int	main()
// {
// 	printf("retV: %d\n", printf(" %d %u %i ", 1, 1, 1));
// 	printf("retF: %d\n", ft_printf(" %d %u %i ", 1, 1, 1));
// }
