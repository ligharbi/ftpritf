int     length(unsigned long long n)
{
        int     i;
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

char	*treat_p(unsigned long long p)
{
	int	len;
	char	*ret;
	len = length(p) + 2;
	ret = malloc (len + 1);
	if (ret == NULL)
		return NULL;
	ret[0] = '0';
	ret[1] = 'x';
	ret[len] = '\0';
	len --;
	if (p == 0)
		ret [len] = '0';
	while (p > 0)
        {
                if (p % 16 >= 10)
                        ret[len] = ('a' + (p % 16 - 10));
                else
                        ret[len] = '0' + (p % 16);
                p = p / 16;
		len --;
	}
        return (ret);
}

