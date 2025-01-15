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
		return NULL;
	r[0] = c;
	r[1] = '\0';
	return (r);
}
char *treat_s(char *s)
{
	int	len;
	char	*r;

	if (!s)
	{
		r = malloc (7);
		if (r == NULL)
			return (NULL);
		r[0] = '(';
		r[1] = 'n';
		r[2] = 'u';
		r[3] = 'l';
		r[4] = 'l';
		r[5] = ')';
		r[6] = '\0';
		return (r);
	}
	else
	{
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
		return(r - len);
	}
}
