/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:55:48 by ligharbi          #+#    #+#             */
/*   Updated: 2025/01/13 09:56:06 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	length(unsigned long long n)
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
	return (i);
}

char	*divide_treat_p(unsigned long long p, char *ret, int len)
{
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

char	*treat_p(unsigned long long p)
{
	int		len;
	char	*ret;

	if (p == 0)
	{
		ret = malloc (6);
		if (ret == NULL)
			return (NULL);
		ret = ft_strcpy (ret, "(nil)");
		return (ret);
	}
	len = length(p) + 2;
	ret = malloc (len + 1);
	if (ret == NULL)
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	ret[len] = '\0';
	len --;
	return (divide_treat_p (p, ret, len));
}
	/*
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
}*/
