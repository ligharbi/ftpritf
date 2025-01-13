/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:55:13 by ligharbi          #+#    #+#             */
/*   Updated: 2025/01/13 09:55:36 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_toupper(char *s)
{
	int	i;
	
	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
		i++;
	}
	return (s);
}

char	*treat_hex(unsigned int n, char c)
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
int	length_hexa(unsigned int n)
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
