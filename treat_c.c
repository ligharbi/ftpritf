/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:54:35 by ligharbi          #+#    #+#             */
/*   Updated: 2025/01/13 09:54:54 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	if (s == NULL)
		return (0);
	while (s[n] != '\0')
	{
		n ++;
	}
	return (n);
}

char	*treat_c(char c)
{
	char	*r;

	r = malloc(2);
	if (r == NULL)
		return (NULL);
	r[0] = c;
	r[1] = '\0';
	return (r);
}

char	*divide_treat_s(int len, char *ret, char *s)
{
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	while (*s != '\0')
	{
		*ret = *s;
		ret ++;
		s ++;
	}
	*ret = '\0';
	return (ret - len);
}

char	*treat_s(char *s)
{
	char	*r;

	r = NULL;
	if (!s)
	{
		r = malloc (7);
		if (r == NULL)
			return (NULL);
		r = ft_strcpy(r, "(null)");
		return (r);
	}
	else
		return (divide_treat_s(ft_strlen(s), r, s));
}
/*
		len = ft_strlen(s);
		r = malloc(len + 1);
		if (r == NULL)
			return (NULL);
		while (*s != '\0')
		{
			*r = *s;
			r ++;
			s ++;
		}
		*r = '\0';
		return (r - len);
	}
}*/
