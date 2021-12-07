/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:30:59 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 13:48:53 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_nbrlen(long n)
{
	int		len;
	long	nbr;

	nbr = n;
	len = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(long n)
{
	char	c;

	if (n < 0)
		n = n * -1;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

int	print_di(t_info *info, va_list ap)
{
	int	tmp_count;
	int	arg_int;

	tmp_count = 0;
	arg_int = va_arg(ap, int);
	if (info->minus > -1)
	{
		tmp_count += print_di_putminus(arg_int);
		tmp_count += print_di_putstr(info, arg_int);
		tmp_count += print_di_putspace(info, arg_int);
	}
	else
	{
		tmp_count += print_di_putspace(info, arg_int);
		tmp_count += print_di_putminus(arg_int);
		tmp_count += print_di_putzero(info, arg_int);
		tmp_count += print_di_putstr(info, arg_int);
	}
	return (tmp_count);
}

int	print_u(t_info *info, va_list ap)
{
	int		tmp_count;
	long	arg_int;

	tmp_count = 0;
	arg_int = va_arg(ap, unsigned int);
	if (info->minus > -1)
	{
		tmp_count += print_di_putminus(arg_int);
		tmp_count += print_di_putstr(info, arg_int);
		tmp_count += print_di_putspace(info, arg_int);
	}
	else
	{
		tmp_count += print_di_putspace(info, arg_int);
		tmp_count += print_di_putminus(arg_int);
		tmp_count += print_di_putzero(info, arg_int);
		tmp_count += print_di_putstr(info, arg_int);
	}
	return (tmp_count);
}
