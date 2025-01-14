/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:59:34 by ligharbi          #+#    #+#             */
/*   Updated: 2025/01/13 10:27:45 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *s, ...);
int	is_ident(char c);
void	ex(int b);
int	ex_length(int b);
void	ft_putnbr(int nb);
int	print_i(int d);
int	length_u(unsigned int n);
void    ft_putnbr_u(unsigned int nb);
int	print_u(unsigned int d);
int	ft_strlen(const char *s);
char	*treat_c(char c);
char	*treat_s(char *s);
char	*ft_toupper(char *s);
int	length_hexa(unsigned int n);
char	*treat_hex(unsigned int n, char c);
int	length(unsigned long long n);
char	*treat_p(unsigned long long p);
int	ft_putstr(char *str);
int	ft_putchar(char c);


#endif
