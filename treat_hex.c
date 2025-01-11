char	*treat_hex(int n, char c)
{
	int	len;
	char	*s;
	
	len = length_hexa(n);
	s = malloc (len + 1);
	if (s == NULL)
		return NULL;
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		len --;
		if (n % 16 >= 10)
			s[len] = ('a' + (n % 16 - 10));
		else
			s[len] = '0' + (n % 16);
		n = n / 16;
	}
	if (c == 'X')
		return (ft_toupper(s));
	return (s);
}
int	length_hexa(int n)
{
	int	i;
	i = 0;
	if (n == 0)
		i ++;
	while (n > 0)
	{
		i += 1;
		n = n / 16;
	}
	return i;
}
