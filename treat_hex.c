char	*m_rev(char *s, char c)
{
	char	*ret;
	size_t	len;

	len = ft_len(s);
	ret = malloc (len + 1);
	if (ret == NULL)
		return (NULL);
	if (c == 'X')
		s = ft_toupper(s);
	while (len > 0)
	{
		*ret = s[len];
		len --;
		ret ++;
	}
	*ret = '\0';
	return ret;
}
char	*treat_hex(int n, char c)
{
	char	*s;
	while (n > 0)
	{
		if (n % 16 >= 10)
			*s = ('a' + (n % 16 - 10));
		else
			*s = '0' + (n % 16);
		n = n / 16;
		s ++;
	}
	*s = '\0';
	return (m_rev(s, c));
}
