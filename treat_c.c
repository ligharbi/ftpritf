char	*treat_c(char c)
{
	char	*r;
	r = alloc(2);
	if (r == NULL)
		return NULL;
		r[0] = c;
	r[1] = '\0';
	return (r);
}
char *treat_s(char *s)
{
	int	len;
	char	*r;

	len = ft_strlen(s);
	r = malloc(len + 1);
	if (r == NULL)
		return (NULL);
	while (*s)
	{
		*r = *s;
		r ++;
			s ++;
		}
	*r = '\0';
	       return(r - len);
}       
