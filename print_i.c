/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:34:45 by ligharbi          #+#    #+#             */
/*   Updated: 2025/01/13 13:41:52 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ex(int b)
{
	if (b == 2147483647)
	{
		write (1, "2147483647", 10);
		return ;
	}
	if (b == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (b == -2147483647)
	{
		write (1, "-2147483647", 11);
		return ;
	}
	if (b == 0)
	{
		write (1, "0", 1);
		return;
	}
	else
		return;
}

int	ex_length(int b)
{
    if (b == 2147483647)
    {
        write (1, "2147483647", 10);
        return (10);
    }
    if (b == -2147483648)
    {
        write (1, "-2147483648", 11);
        return (11);
    }
    if (b == -2147483647)
    {
        write (1, "-2147483647", 11);
        return (11);
    }
    if (b == 0)
    {
        write (1, "0", 1);
        return (1);
    }
    else
    	return (0);
}

void	ft_putnbr(int nb)
{
	int	r;

	r = 0;
	if (nb == 0 || nb == 2147483647 || nb == -2147483648 || nb == -2147483647)
		return (ex(nb));
	if (nb < 0)
	{
		nb = -nb ;
		write (1, "-", 1);
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	r = nb % 10 + '0';
	write(1, &r, 1);
}

int	length_i(int n)
{
	int	r;

	r = 0;
	if (n == 0 || n == 2147483647 || n == -2147483648 || n == -2147483647)
		return (ex_length(n));
	if (n < 0)
	{
		n -= n;
		r++;
	}
	while (n > 0)
	{
		n = n / 10;
		r ++;
	}
	return (r);
}

int	print_i(int d)
{
	int	ret;

	ret = length_i(d);
	ft_putnbr(d);
	return(ret);
}
