/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:34:45 by ligharbi          #+#    #+#             */
/*   Updated: 2025/01/02 14:38:07 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
		return ;
	}
}

void	ft_putnbr(int nb)
{
	int	r;

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

int	print_i(int	d)
{
	ft_putnbr(d);
	return (1);
}
