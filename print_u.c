/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:47:41 by ligharbi          #+#    #+#             */
/*   Updated: 2025/01/14 09:57:22 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int nb)
{
	int	r;

	r = 0;
	if (nb == 0)
	{
		write (1, "0", 1);
		return ;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	r = nb % 10 + '0';
	write(1, &r, 1);
}

int	length_u(unsigned int n)
{
	int	r;

	r = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		r ++;
	}
	return (r);
}

int	print_u(unsigned int d)
{
	int	ret;

	ret = length_u(d);
	ft_putnbr_u(d);
	return(ret);
}
