int	ft_printf (const char *s, ...)
{
	va_list	arg;
	va_start(args, s);
	if(flags)
		treat_flags(s);
	while(get_specifier(*s) != '\0')
	{
		va_arg(arg,get_specifier(*s);
		r = concat(r,treat_arg(va_arg));
		s++;

	}
	print_str(r);
}


