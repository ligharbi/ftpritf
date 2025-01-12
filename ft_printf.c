int	ft_printf (const char *s, ...)
{
	char	*str;
	int	ret_total_inputs;
	va_list	arg;

	va_start(arg, s);
	ret_total_inputs = 0;
	while (*s != '\0')
	{
		if(*s == '%')
		{
			while (is_ident(s) == 1)
			{
				if (*(s+1) == 'd' || *(s+1) == 'i')
					str= treat_d(va_arg(arg, int));
				if (*(s +1) == 'c')
					str = treat_c(va_arg(arg, char));
				if (*(s + 1) == '%' && *s == '%')
					str = treat_c('%');
				if (*(s + 1) == 'p')
                                        str = treat_p(va_arg(arg, unsigned long long));
				if (*(s + 1) == 'x' || *(s + 1) == 'X')
					str = treat_hexa(va_arg(arg, unsigned int));
				ret_total_inputs += ft_putstr(str);
				free(str);
				s++;
			}
		}
		ret_total_inputs ++;
		ft_putchar(*s);
		s ++;
	}
	va_end(arg);
	return (ret_total_inputs);
}


